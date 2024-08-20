#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type)
	{
		enemy_type = type;
	}

	EnemyModel::~EnemyModel()
	{

	}

	void EnemyModel::initialize()
	{
		enemy_current_position = enemy_reference_position;
		movement_direction = MovementDirection::RIGHT;
		enemy_state = EnemyState::PATROLLING;
	}


	sf::Vector2f EnemyModel::getEnemyReferencePostion()
	{
		return enemy_reference_position;
	}

	sf::Vector2f EnemyModel::getEnemyCurrentPostion()
	{
		return enemy_current_position;
	}

	void EnemyModel::setEnemyReferencePostion(sf::Vector2f position)
	{
		enemy_reference_position = position;
	}

	void EnemyModel::setEnemyCurrentPostion(sf::Vector2f position)
	{
		enemy_current_position = position;
	}

	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	EnemyType EnemyModel::getEnemyType()
	{
		return enemy_type;
	}

	void EnemyModel::setEnemyType(EnemyType type)
	{
		enemy_type = type;
	}

	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}

	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemy_state = state;
	}

	Entity::EntityType EnemyModel::getOwnerEntityType()
	{
		return owner_type;
	}
}