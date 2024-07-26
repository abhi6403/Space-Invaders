#include "../../Header/Graphic/GraphicService.h"

namespace Graphic
{
	//constructor
	GraphicService::GraphicService()
	{
		game_window = nullptr; //initializes game window to null
		video_mode = nullptr; //initializes video mode to null
	}

	//destructor
	GraphicService::~GraphicService()
	{
		onDestroy(); //calls destroy method 
	}

	void GraphicService::initialize()
	{
		game_window = createGameWindow(); //assings a new game window to the game_window ptr
		game_window->setFramerateLimit(frame_rate);
	}

	sf::RenderWindow* GraphicService::createGameWindow()
	{
		setVideoMode(); // sets video mode for window
		return new sf::RenderWindow(*video_mode, game_window_title, sf::Style::Fullscreen); // creates and returns new renderwindow object

	}

	void GraphicService::setVideoMode()
	{
		video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel); // allocates and sets the video mode
	}

	void GraphicService::onDestroy()
	{
		delete(video_mode); //deletes the video mode object
		delete(game_window); //deletes the game window object
	}

	void GraphicService::update()
	{

	}

	void GraphicService::render()
	{

	}

	bool GraphicService::isGameWindowOpen()
	{
		return game_window->isOpen(); //returns the open status of the game window 
	}

	sf::RenderWindow* GraphicService::getGameWindow()
	{
		return game_window;
	}

	sf::Color GraphicService::getWindowColor()
	{
		return window_color;
	}
}