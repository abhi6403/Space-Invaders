#include"../../Header/Bullet/Controllers/TorpedoeController.h"
#include"../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	namespace Controller
	{
		TorpedoController::TorpedoController(BulletType type, Entity::EntityType owner_type) :BulletController(type,owner_type)
		{

		}

		TorpedoController::~TorpedoController()
		{

		}

		void TorpedoController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bullet_model->setMovementSpeed(torpedo_movement_speed);
		}
	}
}