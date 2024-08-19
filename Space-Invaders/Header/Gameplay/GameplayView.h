#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"

namespace Gameplay
{
	class GamePlayController;

	class GameplayView
	{
	private:
		
		sf::RenderWindow* game_window;
		sf::Texture background_texture;
		sf::Sprite background_sprite;

		GamePlayController* gameplay_controller;
		UI::UIElement::ImageView* background_image;

		void initializeBackgroundImage();
	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();
	};
}