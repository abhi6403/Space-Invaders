#pragma once
#include <SFML/Graphics.hpp>
#include"../../Header/Collision/ICollider.h"
#include"../../Header/Powerup/PowerupConfig.h"
#include"../../Header/Player/PlayerModel.h"

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
		float elapsed_freez_duration;

		PlayerModel* player_model;
		PlayerView* player_view;

		void processPlayerInput();
		void moveLeft();
		void moveRight();
		
		bool processBulletCollision(ICollider* other_collider);
		bool processPowerupCollision(ICollider* other_collider);
		bool processEnemyCollision(ICollider* other_collider);
		void updateFreezDuration();
		void freezPlayer();

		void updateFireDuration();
		void processBulletFire();
		void FireBullet(bool b_tripple_laser = false);
		void FireBullet(sf::Vector2f position);

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

		void rest();

		void enableShield();
		void enableRapidFire();
		void enableTrippleLaser();

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;

		sf::Vector2f getPlayerPosition();
		PlayerState getPlayerState();
		
	};
}
