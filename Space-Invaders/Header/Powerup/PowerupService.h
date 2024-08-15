#pragma once
#include"../../Header/Collectible/ICollectible.h"
#include<vector>
#include"SFML/System/Vector2.hpp"

namespace Powerup
{
	enum class PowerupType;
	class PowerupController;
	enum class MovementDirection;

	class PowerupService
	{
	private:
		std::vector<Collectible::ICollectible*> powerup_list;
		std::vector<Collectible::ICollectible*>flagged_power_up_list;

		PowerupController* createPowerup(PowerupType powerup_type);
		void destroy();
		void destroyFlaggedPowerup();

	public:
		PowerupService();
		~PowerupService();

		void initialize();
		void update();
		void render();

		PowerupController* spawnPowerup(PowerupType powerup_type, sf::Vector2f position);
		void destroyPowerup(PowerupController* powerup_controller);
	};
}
