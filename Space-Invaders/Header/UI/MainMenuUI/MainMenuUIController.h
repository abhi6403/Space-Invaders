#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			const sf::String background_texture_path = "assets/textures/space_invaders_bg.png";
			const sf::String play_button_texture_path = "assets/textures/play_button.png";
			const sf::String instructions_button_texture_path = "assets/textures/instructions_button.png";
			const sf::String quit_button_texture_path = "assets/textures/quit_button.png";

			const float button_width = 400.f;
			const float button_height = 140.f;

			sf::RenderWindow* game_window;

			sf::Texture background_texture;
			sf::Sprite background_sprite;

			sf::Texture play_button_texture;
			sf::Sprite play_button_sprite;

			sf::Texture instructions_button_texture;
			sf::Sprite instructions_button_sprite;

			sf::Texture quit_button_texture;
			sf::Sprite quit_button_sprite;

			void initializeBackgroundSprite();
			void scaleBackgroundSprite();

			void initializeButtons();
			bool LoadButtonTexturesFromFile();
			void setButtonSprites();

			void scaleAllButtons();
			void scaleButton(sf::Sprite* button_to_scale);
			void positionButtons();

			void processButtonInteractions();
			bool clickedButton(sf::Sprite*, sf::Vector2f);

		public:
			MainMenuUIController();

			void initialize();
			void update();
			void render();

		};
	}
}
