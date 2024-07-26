#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Header/Main/GameService.h"
using namespace std;
using namespace Main;
/*
class Player
{
	private:
		int health = 3;
		sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
		int movement_Speed = 5;
		int player_Score = 0;

   public:

	   //Properties
	   sf :: Texture player_texture;
	   sf::Sprite player_sprite;

	   int getScore()
	   {
		   return player_Score;
	   };

	   int getMoveSpeed()
	   {
		   return movement_Speed;
	   };

	   sf::Vector2f getPosition()
	   {
		   return position;
	   };
	   void setScore(int newScore)
	   {
		   player_Score = newScore;
	   };

	   void takeDamage()
	   {

	   };

	   //Functions
	   void move(float offsetX )
	   {
		   position.x += offsetX;

	   };

	   void shootBullets()
	   {

	   };

}; */

int main()
{
	/*//Define the video mode(dimensions)
	sf::VideoMode videomode = sf::VideoMode(800, 600);

	//create a window object with specific dimensions and a title
	sf::RenderWindow window(videomode, "Player Window");

	//using default constructor
	Player player;

	//laod player ship texture
	player.player_texture.loadFromFile("assets/textures/player_ship.png");

	//set the player type variable to the player ship texture
	player.player_sprite.setTexture(player.player_texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//check for window closure
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//handle keyboard input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move(-1.0f * player.getMoveSpeed());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move(1.0f * player.getMoveSpeed());
		}

		//clear the window
		window.clear(sf::Color::Black);

		//set the position of the player sprite
		player.player_sprite.setPosition(player.getPosition());

		//draw the player sprite
		window.draw(player.player_sprite);

		//display what was drawn
		window.display();
	}*/

	GameService* game_service = new GameService;
	game_service->ignite();

	while (game_service->isRunning())
	{
		game_service->update();
		game_service->render();

	}

}