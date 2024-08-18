#pragma once
#include"../../Header/Enemy/EnemyController.h"
#include"../../Header/Powerup/PowerupConfig.h"

namespace Enemy
{
	namespace Controller
	{
		class UFOController : public EnemyController
		{
		private:
			void move() override;
			void moveLeft();
			void moveRight();

			void fireBullet() override;
			void destroy() override;
			Powerup::PowerupType getRandomPowerupType();

		public:
			UFOController(EnemyType type);
			~UFOController();

			void initialize() override;

			virtual void onCollision(ICollider* other_collider)override;
		};
	}
}