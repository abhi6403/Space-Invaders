#include "../../header/Powerup/Controllers/OutscalBombController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../Header/Sound/SoundService.h"

namespace Powerup
{
    namespace Controller
    {
        using namespace Global;
        using namespace Sound;

        OutscalBombController::OutscalBombController(PowerupType type) : PowerupController(type)
        {
        }

        OutscalBombController::~OutscalBombController()
        {
        }

        void OutscalBombController::onCollected()
        {
            applyPowerup();
        }

        void OutscalBombController::applyPowerup()
        {
            ServiceLocator::getInstance()->getEnemyService()->reset();
        }
    }
}