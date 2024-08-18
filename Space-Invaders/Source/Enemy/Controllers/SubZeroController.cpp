#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include"../../Header/Enemy/EnemyView.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Entity/EntityConfig.h"

namespace Enemy
{

	using namespace Global;
	using namespace Bullet;
	using namespace Time;

	namespace Controller
	{
		SubzeroController::SubzeroController(EnemyType type) :EnemyController(type)
		{

		}

		SubzeroController::~SubzeroController()
		{ 

		}

		void SubzeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);

			rate_of_fire = subzero_rate_of_fire;
			vertical_movement_speed = subzero_vertical_movement_speed;
		}

		void SubzeroController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::FROST_BULLET,enemy_model->getOwnerEntityType(),
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}

		void SubzeroController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void SubzeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(currentPosition);
		}

		void SubzeroController::destroy()
		{
			EnemyController::destroy();
		}
	}
}