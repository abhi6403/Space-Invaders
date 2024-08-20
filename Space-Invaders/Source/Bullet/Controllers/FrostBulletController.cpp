#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	namespace Controller
	{
		FrostBulletController::FrostBulletController(BulletType type, Entity::EntityType owner_type) : BulletController(type, owner_type)
		{

		}

		FrostBulletController::~FrostBulletController()
		{

		}

		void FrostBulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bullet_model->setMovementSpeed(frostbullet_movement_speed);
		}
	}
}