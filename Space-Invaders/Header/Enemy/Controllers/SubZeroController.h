#pragma once

#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubZeroController : public EnemyController
        {
        private:
            float vertical_movement_speed = 150.0f;
            float subzero_rate_of_fire = 3.0f;

            void move() override;
            void moveDown();

            void fireBullet() override;

        public:
            SubZeroController(EnemyType type);
            ~SubZeroController();

            void initialize() override;

        };
    }
}
