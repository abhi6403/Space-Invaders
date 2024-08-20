#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{

		SubZeroController::SubZeroController(EnemyType type) : EnemyController(type) { }

		SubZeroController::~SubZeroController()
		{

		}

		void SubZeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			rate_of_fire = subzero_rate_of_fire;
		}

		void SubZeroController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void SubZeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyCurrentPostion();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyCurrentPostion(currentPosition);
		}

		void SubZeroController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::FROST_BULLET, Entity::EntityType::ENEMY,
				enemy_model->getEnemyCurrentPostion() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}
	}
}