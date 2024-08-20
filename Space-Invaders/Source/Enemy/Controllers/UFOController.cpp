#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"
#include "../../Header/Bullet/BulletController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;
	using namespace Powerup;
	using namespace Entity;
	using namespace Collision;

	namespace Controller
	{

		UFOController::UFOController(EnemyType type) : EnemyController(type) { }

		UFOController::~UFOController()
		{

		}

		void UFOController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(getInitialMovementDirection());
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

		MovementDirection UFOController::getInitialMovementDirection()
		{
			static MovementDirection initial_direction = MovementDirection::RIGHT;

			switch (initial_direction)
			{
			case Enemy::MovementDirection::LEFT:
				initial_direction = MovementDirection::RIGHT;
				return initial_direction;

			case Enemy::MovementDirection::RIGHT:
				initial_direction = MovementDirection::LEFT;
				return initial_direction;
			}
		}

		void UFOController::moveLeft()
		{
			sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
			current_position.x -= enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else
			{
				enemy_model->setEnemyCurrentPostion(current_position);
			}
		}

		void UFOController::moveRight()
		{
			sf::Vector2f current_position = enemy_model->getEnemyCurrentPostion();
			current_position.x += enemy_model->horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
				enemy_model->setEnemyReferencePostion(current_position);
			}
			else
			{
				enemy_model->setEnemyCurrentPostion(current_position);
			}
		}

		void UFOController::fireBullet()
		{
		}

		PowerupType UFOController::getRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			int random_value = std::rand() % (static_cast<int>(PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<PowerupType>(random_value);
		}

		void UFOController::onCollision(ICollider* other_collider)
		{
			EnemyController::onCollision(other_collider);
			BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

			if (bullet_controller && bullet_controller->getOwnerEntityType() != EntityType::ENEMY)
			{
				ServiceLocator::getInstance()->getPowerupService()->spawnPowerup(getRandomPowerupType(), enemy_model->getEnemyCurrentPostion());
				return;
			}
		}

	}
}