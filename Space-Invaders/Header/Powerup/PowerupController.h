#pragma once

#include "../../Header/Collectible/ICollectible.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Collision/ICollider.h"

namespace Powerup
{
	class PowerupView;
	class PowerupModel;
	enum class PowerupType;

	class PowerupController :public Collectible::ICollectible, public Collision::ICollider
	{
	private:
		PowerupView* powerup_view;
		PowerupModel* powerup_model;

		virtual void applyPowerup() = 0;
		void updatePowerupPosition();
		void handleOutOfBounds();

	public:
		PowerupController(PowerupType power_type);
		virtual ~PowerupController();

		void initialize(sf::Vector2f position) override;
		void update() override;
		void render() override;

		sf::Vector2f getCollectiblePosition() override;
		void onCollected() override;

		PowerupType getPowerupType();

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;
	};
}