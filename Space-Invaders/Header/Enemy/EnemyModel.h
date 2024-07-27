#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,

	};
	class EnemyModel
	{
	private:
		sf::Vector2f reference_position = sf::Vector2f(50.f, 50.f);
		sf::Vector2f enemy_position;

		MovementDirection movement_direction;

	public:
		EnemyModel();
		~EnemyModel();

		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);

		const float vertical_travel_distance = 100.f;
		const float enemy_movement_speed = 250.0f;

		void initialize();

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f positon);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);
	};
}
