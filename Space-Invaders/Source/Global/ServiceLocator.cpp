#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global
{
	using namespace Graphic;
	using namespace Event;
	using namespace Time;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;
	using namespace Gameplay;
	using namespace Element;
	using namespace Sound;
	using namespace Bullet;
	using namespace Powerup;
	using namespace Collision;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		time_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;
		gameplay_service = nullptr;
		element_service = nullptr;
		sound_service = nullptr;
		bullet_service = nullptr;
		powerup_service = nullptr;
		collision_service = nullptr;
		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
		player_service = new PlayerService();
		time_service = new TimeService();
		ui_service = new UIService();
		enemy_service = new EnemyService();
		gameplay_service = new GameplayService();
		element_service = new ElementService();
		bullet_service = new BulletService();
		sound_service = new SoundService();
		powerup_service = new PowerupService();
		collision_service = new CollisionService();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(player_service);
		delete(time_service);
		delete(ui_service);
		delete(enemy_service);
		delete(gameplay_service);
		delete(element_service);
		delete(bullet_service);
		delete(sound_service);
		delete(powerup_service);
		delete(collision_service);
		graphic_service = nullptr;
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		player_service->initialize();
		time_service->initialize();
		ui_service->initialize();
		enemy_service->initialize();
		gameplay_service->initialize();
		element_service->initialize();
		sound_service->initialize();
		powerup_service->initialize();
		collision_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		time_service->update();
		event_service->update();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->update();
			player_service->update();
			enemy_service->update();
			bullet_service->update();
			element_service->update();
			powerup_service->update();
			collision_service->update();
		}
		ui_service->update();
	}

	

	void ServiceLocator::render()
	{
		graphic_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			player_service->render();
			enemy_service->render();
			bullet_service->render();
			element_service->render();
			powerup_service->render();
			
		}

		ui_service->render();
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}

	EnemyService* ServiceLocator::getEnemyService()
	{
		return enemy_service;
	}

	GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	ElementService* ServiceLocator::getElementService()
	{
		return element_service;
	}

	SoundService* ServiceLocator::getSoundService()
	{
		return sound_service;
	}

	BulletService* ServiceLocator::getBulletService()
	{
		return bullet_service;
	}

	PowerupService* ServiceLocator::getPowerupService()
	{
		return powerup_service;
	}

	CollisionService* ServiceLocator::getCollisionService()
	{
		return collision_service;
	}
}