#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Enemy
{
	enum class EnemyType;
	enum class EnemyState;
	enum class MovementDirection;

	class EnemyModel
	{
	private:
		sf::Vector2f enemy_reference_position = sf::Vector2f(50.f, 50.f);
		sf::Vector2f enemy_current_position;
		Entity::EntityType owner_type;
		EnemyType enemy_type;
		EnemyState enemy_state;
		MovementDirection movement_direction;

	public:

		float horizontal_movement_speed = 200.0f;
		float vertical_movement_speed = 30.f;
		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 50.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 50.f);
		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f);

		const float vertical_travel_distance = 100.0f;

		EnemyModel(EnemyType type);
		~EnemyModel();

		void initialize();

		sf::Vector2f getEnemyReferencePostion();
		sf::Vector2f getEnemyCurrentPostion();

		void setEnemyReferencePostion(sf::Vector2f position);
		void setEnemyCurrentPostion(sf::Vector2f position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		EnemyType getEnemyType();
		void setEnemyType(EnemyType type);

		EnemyState getEnemyState();
		void setEnemyState(EnemyState state);

		Entity::EntityType getOwnerEntityType();

	};
}
