#include"../../Header/Gameplay/GameplayService.h"
#include"../../Header/Gameplay/GameplayController.h"
#include"../../Header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Player;
	using namespace Enemy;
	using namespace Element;
	using namespace Bullet;

	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		delete(gameplay_controller);
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
	}

	void GameplayService::restart()
	{
		ServiceLocator::getInstance()->getPlayerService()->reset();
		ServiceLocator::getInstance()->getEnemyService()->reset();
		ServiceLocator::getInstance()->getBulletService()->reset();
		ServiceLocator::getInstance()->getElementService()->reset();
	}
}