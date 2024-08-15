#include"../../Header/Powerup/Controllers/TripleLaserController.h"
#include"../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	namespace Controller
	{
		using namespace Global;

		TripleLaserController::TripleLaserController(PowerupType type) :PowerupController(type)
		{

		}

		TripleLaserController::~TripleLaserController()
		{

		}

		void TripleLaserController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->reset();
		}
	}
}