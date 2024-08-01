#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	class EnemyController
	{
	private:
		EnemyView* enemy_view;
		EnemyModel* enemy_model;
		
		void moveLeft();
		void moveRight();
		void moveDown();
		virtual void move() = 0;
		void getRandomInitialPosition();
		void handleOutOfBounds();

	public:
		EnemyController();
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
	};
}