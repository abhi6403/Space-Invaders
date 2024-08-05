#pragma once
#include <SFML/Graphics.hpp>

namespace Graphic
{
	class GraphicService
	{
	private:
		const std::string game_window_title = "Outscal Presents - Alien Invader";

		const int game_window_width = 1920;
		const int game_window_height = 1080;
		const int frame_rate = 60;

		const sf::Color window_color = sf::Color::Blue;

		sf::VideoMode* video_mode; 
		sf::RenderWindow* game_window; 

		void setVideoMode();  
		void onDestroy(); 

	public:
		GraphicService();
		~GraphicService(); 

		sf::RenderWindow* createGameWindow(); 

		void initialize(); 
		void update();
		void render();
		bool isGameWindowOpen(); 

		sf::RenderWindow* getGameWindow();  
		sf::Color getWindowColor(); 

	};
}