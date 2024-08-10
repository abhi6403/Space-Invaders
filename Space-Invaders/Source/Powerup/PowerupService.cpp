#include"../../Header/Powerup/PowerupService.h"
#include"../../Header/Powerup/PowerupConfig.h"
#include"../../Header/Powerup/PowerupController.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Powerup/Controllers/OutscalBombController.h"
#include"../../Header/Powerup/Controllers/RapidFireController.h"
#include"../../Header/Powerup/Controllers/ShieldController.h"
#include"../../Header/Powerup/Controllers/TripleLaserController.h"

namespace Powerup
{
	using namespace Controller;
	using namespace Global;
	using namespace Collectible;

	PowerupService::PowerupService()
	{

	}

	PowerupService::~PowerupService()
	{
		destroy();
	}

	void PowerupService::initialize()
	{

	}

	void PowerupService::update()
	{
		for (int i = 0; i < powerup_list.size(); i++)powerup_list[i]->update();
	}

	void PowerupService::render()
	{
		for (int i = 0; i < powerup_list.size(); i++)powerup_list[i]->render();
	}

	PowerupController* PowerupService::createPowerup(PowerupType powerup_type)
	{
		switch (powerup_type)
		{
		case::Powerup::PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);

		case::Powerup::PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return new TripleLaserController(Powerup::PowerupType::TRIPPLE_LASER);

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);
		}
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType powerup_type, sf::Vector2f position)
	{
		PowerupController* powerup_controller = createPowerup(powerup_type);

		powerup_controller->initialize(position);
		powerup_list.push_back(powerup_controller);
		return powerup_controller;
	}

	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), powerup_controller), powerup_list.end());
		delete(powerup_controller);
	}

	void PowerupService::destroy()
	{
		for (int i = 0; i < powerup_list.size(); i++) delete (powerup_list[i]);
	}
}