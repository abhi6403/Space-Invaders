#include "../../header/Powerup/Controllers/ShieldController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        using namespace Global;

        ShieldController::ShieldController(PowerupType type) : PowerupController(type)
        {
        }

        ShieldController::~ShieldController()
        {
        }

        void ShieldController::onCollected()
        {
            applyPowerup();
        }

        void ShieldController::applyPowerup()
        {
            ServiceLocator::getInstance()->getPlayerService()->enableShield();
        }
    }
}