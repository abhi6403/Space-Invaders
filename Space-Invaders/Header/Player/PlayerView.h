#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		const float player_sprite_width = 60.f;
		const float player_sprite_height = 60.f;

		const float shield_sprite_width = 120.f;
		const float shield_sprite_height = 120.f;

		PlayerController* player_controller;

		UI::UIElement::ImageView* player_image;
		UI::UIElement::ImageView* player_shield;

		void createUIElements();
		void initializeImage();
		sf::String getPlayerTexturePath();
		void destroy();

	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();

		const sf::Sprite& getPlayerSprite();
		void setPlayerHighlight(bool b_highlight);
	};
}