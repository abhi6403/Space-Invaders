#pragma once

#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ZapperController : public EnemyController
        {
        private:
            float vertical_travel_distance = 200.0f;
            float zapper_rate_of_fire = 2.0f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();

            void fireBullet() override;

        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void initialize() override;


        };
    }
}
