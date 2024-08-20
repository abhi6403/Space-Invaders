#include "../../Header/Powerup/PowerupModel.h"

namespace Powerup
{
	PowerupModel::PowerupModel(PowerupType type)
	{
		powerup_type = type;
	}

	PowerupModel::~PowerupModel()
	{

	}

	void PowerupModel::initialize(sf::Vector2f position)
	{
		powerup_position = position;
	}

	sf::Vector2f PowerupModel::getPowerupPosition()
	{
		return powerup_position;
	}

	void PowerupModel::setPowerupPosition(sf::Vector2f position)
	{
		powerup_position = position;
	}

	float PowerupModel::getPowerupSpeed()
	{
		return movement_speed;
	}

	void PowerupModel::setPowerupSpeed(float speed)
	{
		movement_speed = speed;

	}

	PowerupType PowerupModel::getPowerupType()
	{
		return powerup_type;
	}

	void PowerupModel::setPowerupType(PowerupType type)
	{
		powerup_type = type;
	}
}