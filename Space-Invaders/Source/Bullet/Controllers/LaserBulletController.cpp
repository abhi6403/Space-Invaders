#include"../../Header/Bullet/Controllers/LaserBulletController.h"

namespace Bullet
{
	namespace Controller
	{
		LaserBulletController::LaserBulletController(BulletType type, Entity::EntityType owner_type):BulletController(type,owner_type)
		{

		}

		LaserBulletController::~LaserBulletController()
		{

		}

		void LaserBulletController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
		}
	}
}