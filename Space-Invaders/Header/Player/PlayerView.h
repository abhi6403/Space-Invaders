#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		const sf::String player_texture_path = "assets/textures/player_ship.png";
		const float player_sprite_width = 60.0f;
		const float player_sprite_height = 60.0f;
		sf::Texture player_texture;
		sf::Sprite player_sprite;

		PlayerController* player_controller;

		sf::RenderWindow* game_window;

		void initializePlayerSprite();
		void scalePlayerSprite();



	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();

	};
}
