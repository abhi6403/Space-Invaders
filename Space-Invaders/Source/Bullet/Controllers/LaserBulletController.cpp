#include"../../Header/Bullet/Controllers/LaserBulletController.h"

namespace Bullet
{
	namespace Controller
	{
		LaserBulletController::LaserBulletController(BulletType bullet_type, Entity::EntityType owner_type):BulletController(bullet_type,owner_type)
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