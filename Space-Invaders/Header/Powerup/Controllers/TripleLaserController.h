#pragma once

#include "../../header/Powerup/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class TripleLaserController : public PowerupController
        {
        public:
            TripleLaserController(PowerupType type);
            virtual ~TripleLaserController();

            void onCollected() override;

            void applyPowerup();
        };
    }
}