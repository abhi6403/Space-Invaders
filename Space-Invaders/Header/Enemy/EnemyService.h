#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;

	class EnemyService
	{
	private:
		void destroy();

		EnemyController* enemy;

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* spawnEnemy();
	};
}