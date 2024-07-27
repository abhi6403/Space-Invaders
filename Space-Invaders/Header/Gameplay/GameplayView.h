#pragma once
#include<SFML/Graphics.hpp>

namespace Gameplay
{
	class GameplayView
	{
	private:
		const sf::String background_texture_path = "assets/textures/space_invaders_bg.png";
		
		sf::RenderWindow* game_window;
		sf::Texture background_texture;
		sf::Sprite background_sprite;

		void initializeBackGroundSprite();
		void scaleBackGroundSprite();

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();
	};
}