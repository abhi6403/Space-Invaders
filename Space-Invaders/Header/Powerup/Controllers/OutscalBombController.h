#pragma once

#include "../../header/Powerup/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class OutscalBombController : public PowerupController
        {
        public:
            OutscalBombController(PowerupType type);
            virtual ~OutscalBombController();

            void onCollected() override;

            void applyPowerup();
        };
    }
}