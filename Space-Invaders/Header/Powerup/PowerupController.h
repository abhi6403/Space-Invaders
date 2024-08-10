#pragma once
#include"../../Header/Collectible/ICollectible.h"

namespace Powerup
{
	class PowerupView;
	class PowerupModel;

	enum class PowerupType;

	class PowerupController :public Collectible::ICollectible
	{
	protected:
		PowerupView* powerup_view;
		PowerupModel* powerup_model;

		void updatePowerupPosition();
		void handleOutOfBounds();

	public:
		PowerupController(PowerupType type);
		virtual ~PowerupController();

		void initialize(sf::Vector2f position)override;
		void update()override;
		void render()override;

		void onCollected()override;

		sf::Vector2f getCollectiblePosition()override;
		PowerupType getPowerupType();
	};
}

