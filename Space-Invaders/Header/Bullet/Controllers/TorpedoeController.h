#pragma once
#include"../../Header/Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class TorpedoController :public BulletController
		{
		private:
			const float torpedo_movement_speed = 200.f;

		public:
			TorpedoController(BulletType type,Entity::EntityType owner_type);
			~TorpedoController();

			void initialize(sf::Vector2f position, MovementDirection direction)override;
		};
	}
}
