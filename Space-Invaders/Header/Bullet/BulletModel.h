#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	enum class BulletType;
	enum class MovementDirection;

	class BulletModel
	{
	private:
		float movement_speed = 300.f;
		sf::Vector2f bullet_position;

		BulletType bullet_type;
		Entity::EntityType owner_type;
		MovementDirection movement_direction;

	public:
		BulletModel(BulletType type, Entity::EntityType owner_type);
		~BulletModel();

		void initialize(sf::Vector2f position, MovementDirection direction);

		sf::Vector2f getBulletPosition();
		void setBulletPosition(sf::Vector2f position);
		
		BulletType getBulletType();
		void setBulletType(BulletType type);

		Entity::EntityType getOwnerEntityType();

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		float getMovementSpeed();
		void setMovementSpeed(float speed);
	};
}