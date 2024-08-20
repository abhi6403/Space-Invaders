#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	enum class MovementDirection;
	enum class BulletType;

	class BulletModel
	{
	private:
		MovementDirection movement_direction;
		sf::Vector2f bullet_position;
		BulletType bullet_type;
		Entity::EntityType owner_type;
		float movement_speed = 300.0f;

	public:
		BulletModel(BulletType type, Entity::EntityType entity_type);
		~BulletModel();

		void initialize(sf::Vector2f position, MovementDirection direction);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		sf::Vector2f getBulletPosition();
		void setBulletPosition(sf::Vector2f position);

		BulletType getBulletType();
		void setBulletType(BulletType type);

		float getMovementSpeed();
		void setMovementSpeed(float speed);

		Entity::EntityType getOwnerEntityType();
	};
}