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

		sf::VideoMode* video_mode; //pointer to videomode 
		sf::RenderWindow* game_window; //ptr to renderwindow

		void setVideoMode();  // setting video mode
		void onDestroy(); //to run when window is deleted 

	public:
		GraphicService();
		~GraphicService(); // cleanup

		sf::RenderWindow* createGameWindow(); //create gamewindow

		void initialize(); //lifecycle functions
		void update();
		void render();
		bool isGameWindowOpen(); // check if window is open

		sf::RenderWindow* getGameWindow(); //getter for the game window instance 
		sf::Color getWindowColor(); //get the color

	};
}