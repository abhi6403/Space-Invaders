#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class FrostBulletController : public BulletController
		{
		private:
			float frostbullet_movement_speed = 500.0f;

		public:
			FrostBulletController(BulletType type, Entity::EntityType owner_type);
			~FrostBulletController();


			void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
		};
	}
}
