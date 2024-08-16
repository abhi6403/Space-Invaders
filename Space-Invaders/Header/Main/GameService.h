#pragma once
#include <SFML/Graphics.hpp>

namespace Global
{
	class ServiceLocator;
}
namespace Main
{

	enum class GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY,
		SPLASH_SCREEN,
		INSTRUCTIONS,
		CREDITS,
	};
	class GameService
	{
	private:

		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;
		static GameState current_state;

		void showSplashScreen();
		void initialize();		
		void initializeVariables();
		void destroy();			

	public:
		GameService();			
		~GameService();	    

		void ignite();			
		void update();			
		void render();			
		bool isRunning();	
		static void setGameState(GameState new_state);
		static GameState getGameState();
	};
}
