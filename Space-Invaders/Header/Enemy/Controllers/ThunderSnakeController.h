#pragma once
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class ThunderSnakeController : public EnemyController
		{
		private:
			float horizontal_movement_speed = 250.f;
			float vertical_movement_speed = 25.f;
			float thunder_snake_rate_of_fire = 2.f;

			void move() override;
			void moveLeft();
			void moveRight();
			void fireBullet() override;

		public:
			ThunderSnakeController(EnemyType type);
			~ThunderSnakeController();

			void initialize() override;
		};
	}
}
