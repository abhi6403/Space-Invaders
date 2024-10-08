#pragma once
#include"../../Header/UI/Interface/IUIController.h"
#include"../../Header/UI/UIElement/ImageView.h"
#include"../../Header/UI/UIElement/ButtonView.h"
#include"../../Header/UI/UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			const float font_size = 40.f;

			const float text_y_position = 15.f;
			const float enemies_killed_text_x_position = 60.f;

			const float player_lives_y_offset = 25.f;
			const float player_lives_x_offset = 1850.f;
			const float player_lives_spacing = 60.f;

			const float player_sprite_width = 30.f;
			const float player_sprite_height = 30.f;

			const sf::Color text_color = sf::Color::White;

			UI::UIElement::ImageView* player_image;
			UI::UIElement::TextView* enemies_killed_text;

			void createUIElements();
			void initializeImage();
			void initializeText();

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize();
			void update();
			void render();
			void show();

			void updateEnemiesKilledText();
			void drawPlayerLives();
		};
	}
}