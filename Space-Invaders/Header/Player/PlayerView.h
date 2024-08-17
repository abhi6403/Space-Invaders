#pragma once
#include <SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
	
		const float player_sprite_width = 60.0f;
		const float player_sprite_height = 60.0f;
		

		PlayerController* player_controller;
		UI::UIElement::ImageView* player_image;

		void createUIElements();
		void initializeImage();

		void destroy();

	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();

		void setPlayerHighlight(bool b_highlight);
		const sf::Sprite& getPlayerSprite();

	};
}
