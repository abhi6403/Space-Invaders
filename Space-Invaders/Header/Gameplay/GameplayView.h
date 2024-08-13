#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"

namespace Gameplay
{
	class GameplayView
	{
	private:
		
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