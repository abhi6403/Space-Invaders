#pragma once
#include <SFML/Graphics.hpp>
#include"../../Header/Entity/EntityConfig.h"
#include"../../Header/UI/GameplayUI/GameplayUIController.h"

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD,
		FROZEN,
	};

	class PlayerModel
	{
	private:

		friend class PlayerController;

		friend void UI::GameplayUI::GameplayUIController::updateEnemiesKilledText();
		friend void UI::GameplayUI::GameplayUIController::drawPlayerLives();

		const int max_player_lives = 3;

		sf::Vector2f initial_player_position = sf::Vector2f(950.f, 950.f);
		sf::Vector2f player_position;

		PlayerState player_state;
		Entity::EntityType owner_type;

		int player_score;

		static int player_lives;
		static int enemies_killed;

		bool b_shield;
		bool b_rapid_fire;
		bool b_tripple_laser;

	public:
		const float player_movement_speed = 350.0f;

		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);
		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f);
		const sf::Vector2f second_weapon_position_offset = sf::Vector2f(45.f, 0.f);
		const sf::Vector2f third_weapon_position_offset = sf::Vector2f(-45.f, 0.f);

		const float shield_powerup_duration = 10.f;
		const float rapid_fire_powerup_duration = 10.f;
		const float tripple_laser_powerup_duration = 10.f;

		const float freeze_duration = 2.f;
		
		const float fire_cooldown_duration = 0.2f;
		const float rapid_fire_cooldown_duration = 0.05f;
		const float tripple_laser_position_offset = 30.f;

		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;

		float elapsed_fire_duration;
		float elapsed_freeze_duration;

		PlayerModel();
		~PlayerModel();

		void initialize();
		void reset();

		sf::Vector2f getPlayerPosition();
		void setPlayerPosition(sf::Vector2f position);

		int getPlayerScore();
		void setPlayerScore(int score);

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);

		Entity::EntityType getOwnerEntityType();

		bool isShieldEnabled();
		bool isRapidFireEnabled();
		bool isTrippleFireEnabled();

		void setShieldState(bool value);
		void setRapidFireState(bool value);
		void setTrippleFireState(bool value);
	};
}
