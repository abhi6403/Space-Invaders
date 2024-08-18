#include"../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include"../../Header/Enemy/EnemyModel.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Entity/EntityConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;
	using namespace Time;

	namespace Controller
	{
		ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type)
		{
		
		}

		ThunderSnakeController::~ThunderSnakeController()
		{

		}

		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
			rate_of_fire = thundersnake_rate_of_fire;
		}

		void ThunderSnakeController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::TORPEDO,enemy_model->getOwnerEntityType(),
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}


		void ThunderSnakeController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;
			}
		}

        void ThunderSnakeController::moveLeft()
        {
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += thundersnake_vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x -= thundersnake_horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
            
        }


        void ThunderSnakeController::moveRight()
        {
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += thundersnake_vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x += thundersnake_horizontal_movement_speed* ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
            
        }

		void ThunderSnakeController::destroy()
		{

			EnemyController::destroy();
		}
	}
}

