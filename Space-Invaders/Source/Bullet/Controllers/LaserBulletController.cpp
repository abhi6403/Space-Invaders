#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		LaserBulletController::LaserBulletController(BulletType type, Entity::EntityType owner_type) : BulletController(type, owner_type)
		{

		}

		LaserBulletController::~LaserBulletController()
		{

		}

		void LaserBulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
		{
			BulletController::initialize(position, direction);
		}
	}
}