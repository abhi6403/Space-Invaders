#include"../../Header/Powerup/Controllers/ShieldController.h"
#include"../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	namespace Controller
	{
		using namespace Global;

		ShieldController::ShieldController(PowerupType type) :PowerupController(type)
		{

		}

		ShieldController::~ShieldController()
		{

		}

		void ShieldController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->reset();
		};
	}
}