#pragma once
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class ThunderSnakeController : public EnemyController
		{
		private:
			float thundersnake_horizontal_movement_speed = 250.f;
			float thundersnake_vertical_movement_speed = 25.f;
			float thundersnake_rate_of_fire = 3.f;

			void move() override;
			void moveLeft();
			void moveRight();
			void fireBullet() override;
			void destroy() override;

		public:
			ThunderSnakeController(EnemyType type);
			~ThunderSnakeController();

			void initialize() override;
		};
	}
}
