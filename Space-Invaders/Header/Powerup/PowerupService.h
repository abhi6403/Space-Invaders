#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include "../../Header/Collectible/ICollectible.h"
#include "../../Header/Collectible/ICollectible.h"

namespace Powerup
{
	class PowerupController;
	enum class PowerupType;

	class PowerupService
	{
	private:
		std::vector<Collectible::ICollectible*> powerup_list;
		std::vector<Collectible::ICollectible*> flagged_powerup_list;

		PowerupController* createPowerup(PowerupType powerup_type);
		void destroyFlaggedPowerup();
		void destroy();

	public:
		PowerupService();
		virtual ~PowerupService();

		void initialize();
		void update();
		void render();

		PowerupController* spawnPowerup(PowerupType powerup_type, sf::Vector2f position);
		void destroyPowerup(PowerupController* powerup_controller);
	};
}