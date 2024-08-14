#include"../../Header/Enemy/Controllers/UFOController.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Enemy/EnemyModel.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Bullet/BulletService.h"
#include"../../Header/Entity/EntityConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{
		UFOController::UFOController(EnemyType type) : EnemyController(type)
		{

		}

		UFOController::~UFOController()
		{

		}

		void UFOController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::LEFT);
		}

		void UFOController::fireBullet()
		{

		}

		Powerup::PowerupType UFOController::getRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<Powerup::PowerupType>(random_value);
		}

		void UFOController::move()
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

		void UFOController::moveLeft()
		{
			sf::Vector2f currentposition = enemy_model->getEnemyPosition();

			currentposition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentposition.x <= enemy_model -> left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
				enemy_model->setReferencePosition(currentposition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentposition);
			}
		}

		void UFOController::moveRight()
		{
			sf::Vector2f currentposition = enemy_model->getEnemyPosition();

			currentposition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentposition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
				enemy_model->setReferencePosition(currentposition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentposition);
			}
		}
	}
}