#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	BulletModel::BulletModel(BulletType type, Entity::EntityType type_of_owner)
	{
		bullet_type = type;
		owner_type = type_of_owner;
	}

	BulletModel::~BulletModel()
	{

	}

	void BulletModel::initialize(sf::Vector2f position, MovementDirection direction)
	{
		bullet_position = position;
		movement_direction = direction;
	}

	MovementDirection BulletModel::getMovementDirection()
	{
		return movement_direction;
	}

	void BulletModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	sf::Vector2f BulletModel::getBulletPosition()
	{
		return bullet_position;
	}

	void BulletModel::setBulletPosition(sf::Vector2f position)
	{
		bullet_position = position;
	}

	BulletType BulletModel::getBulletType()
	{
		return bullet_type;
	}

	void BulletModel::setBulletType(BulletType type)
	{
		bullet_type = type;
	}

	float BulletModel::getMovementSpeed()
	{
		return movement_speed;
	}

	void BulletModel::setMovementSpeed(float speed)
	{
		movement_speed = speed;
	}

	Entity::EntityType BulletModel::getOwnerEntityType()
	{
		return owner_type;
	}
}