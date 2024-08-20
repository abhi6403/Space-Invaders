#pragma once

#include <SFML/Graphics.hpp>

namespace Powerup
{
	enum class PowerupType;

	class PowerupModel
	{
	private:
		sf::Vector2f powerup_position;
		float movement_speed = 300.0f;
		PowerupType powerup_type;

	public:
		PowerupModel(PowerupType type);
		~PowerupModel();

		void initialize(sf::Vector2f position);

		sf::Vector2f getPowerupPosition();
		void setPowerupPosition(sf::Vector2f position);

		float getPowerupSpeed();
		void setPowerupSpeed(float speed);

		PowerupType getPowerupType();
		void setPowerupType(PowerupType type);

	};
}