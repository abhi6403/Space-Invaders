#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Collision/ICollider.h"
#include "../../Header/Player/PlayerModel.h"

namespace Player
{
	enum class PlayerState;
	class PlayerView;

	class PlayerController : public Collision::ICollider
	{
	private:
		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;
		float elapsed_fire_duration;
		float elapsed_freeze_duration;

		PlayerModel* player_model;
		PlayerView* player_view;

		void processPlayerInput();
		void moveLeft();
		void moveRight();

		bool processBulletCollision(ICollider* other_collider);
		bool processPowerupCollision(ICollider* other_collider);
		bool processEnemyCollision(ICollider* other_collider);
		void updateFreezeDuration();
		void freezePlayer();

		void updateFireDuration();
		void processBulletFire();
		void fireBullet(bool b_tripple_laser = false);
		void fireBullet(sf::Vector2f position);

		void updatePowerupDuration();

		void disableShield();
		void disableRapidFire();
		void disableTrippleLaser();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		void reset();

		void enableShield();
		void enableRapidFire();
		void enableTrippleLaser();

		bool isShieldEnabled();

		sf::Vector2f getPlayerPosition();
		PlayerState getPlayerState();

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;

		Entity::EntityType getOwnerEntityType();

		void decreasePlayerLive();
		inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
	};
}