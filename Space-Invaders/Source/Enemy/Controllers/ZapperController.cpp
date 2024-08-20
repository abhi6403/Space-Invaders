#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{
		ZapperController::ZapperController(EnemyType type) : EnemyController(type) { }

		ZapperController::~ZapperController()
		{

		}

		void ZapperController::initialize()
		{
			EnemyController::initialize();
			rate_of_fire = zapper_rate_of_fire;
		}

		void ZapperController::move()
		{

			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;

			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}
		void ZapperController::moveLeft()
		{
			sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
			current_position.x -= enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setEnemyReferencePostion(current_position);
			}
			else
			{
				enemy_model->setEnemyCurrentPostion(current_position);
			}
		}

		void ZapperController::moveRight()
		{
			sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
			current_position.x += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setEnemyReferencePostion(current_position);
			}
			else
			{
				enemy_model->setEnemyCurrentPostion(current_position);
			}
		}

		void ZapperController::moveDown()
		{
			sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
			current_position.y += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.y >= enemy_model->getEnemyReferencePostion().y + enemy_model->vertical_travel_distance)
			{
				if (enemy_model->getEnemyReferencePostion().x <= enemy_model->left_most_position.x)
				{
					enemy_model->setMovementDirection(MovementDirection::RIGHT);

				}
				else if (enemy_model->getEnemyReferencePostion().x >= enemy_model->left_most_position.x)
				{
					enemy_model->setMovementDirection(MovementDirection::LEFT);

				}
			}
			else
			{
				enemy_model->setEnemyCurrentPostion(current_position);

			}
		}

		void ZapperController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET, Entity::EntityType::ENEMY,
				enemy_model->getEnemyCurrentPostion() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}

	}
}