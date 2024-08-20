#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class TorpedoController : public BulletController
		{
		private:
			float torpedo_movement_speed = 200.0f;

		public:
			TorpedoController(BulletType type, Entity::EntityType owner_type);
			~TorpedoController();


			void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
		};
	}
}
