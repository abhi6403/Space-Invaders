#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include"../../Header/Enemy/Controllers/ZapperController.h"
#include"../../Header/Bullet/BulletConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;

	EnemyController::EnemyController(EnemyType type)
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel(type);
	}

	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setEnemyPosition(getRandomInitialPosition());
		enemy_view->initialize(this); 
	}

	void EnemyController::update()
	{
		move();
		updateFireTimer();
		processBulletFire();
		enemy_view->update();
		handleOutOfBounds();
	}

	/*void EnemyController::move()
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
	}*/

	/*void EnemyController::moveLeft()
	{
		// Get current pos
		// Move left by multiplying by speed and delta time
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		//check for bounds
		if (currentPosition.x <= enemy_model->left_most_position.x)
		{
			//if reached the left most pos
			//start moving down
			//set ref pos for the downwards movement
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setReferencePosition(currentPosition);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}

	void EnemyController::moveRight()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.x >= enemy_model->right_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setReferencePosition(currentPosition);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}

	void EnemyController::moveDown()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		//check if enemy has moved the specified distance downwards
		if (currentPosition.y >= enemy_model->getReferencePosition().y + enemy_model->vertical_travel_distance)
		{
			//check where to move them based on position
			if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x) enemy_model->setMovementDirection(MovementDirection::RIGHT);
			else enemy_model->setMovementDirection(MovementDirection::LEFT);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}*/

	void EnemyController::render()
	{
		enemy_view->render();
	}

	void EnemyController::updateFireTimer()
	{
		elapsed_fire_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyController::processBulletFire()
	{
		if (elapsed_fire_duration >= rate_of_fire)
		{
			fireBullet();
			elapsed_fire_duration = 0.f;
		}
	}

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));

		float x_position = enemy_model->left_most_position.x + x_offset_distance;

		float y_position = enemy_model->left_most_position.y;

		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemyPosition = getEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (enemyPosition.x<0 || enemyPosition.x>windowSize.x ||
			enemyPosition.y<0 || enemyPosition.y>windowSize.y)
		{
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
		}
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}
}