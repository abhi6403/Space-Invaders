#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel();
	}

	EnemyController::~EnemyController()
	{
		delete(enemy_view);
		delete(enemy_model);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		move();
		enemy_view->update();
	}

	void EnemyController::render()
	{
		enemy_view->render();
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

	void EnemyController::moveLeft()
	{
		sf::Vector2f currentposition = enemy_model->getEnemyPosition();
		currentposition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentposition.x <= enemy_model->left_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setReferencePosition(currentposition);
		}
		else enemy_model->setEnemyPosition(currentposition);
	}

	void EnemyController::moveDown()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.y >= enemy_model->getReferencePosition().y + enemy_model->vertical_travel_distance)
		{
			if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x) enemy_model->setMovementDirection(MovementDirection::RIGHT);
			else enemy_model->setMovementDirection(MovementDirection::LEFT);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}
}
