#pragma once

#include "../../header/Powerup/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class RapidFireController : public PowerupController
        {
        public:
            RapidFireController(PowerupType type);
            virtual ~RapidFireController();

            void onCollected() override;

            void applyPowerup();
        };
    }
}