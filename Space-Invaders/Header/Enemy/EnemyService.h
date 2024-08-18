#pragma once
#include <vector>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	private:

		const float spawn_interval = 2.f;

		std::vector<EnemyController*> enemy_list;
		std::vector<EnemyController*>flagged_enemy_list;
		float spawn_timer;

		EnemyController* createEnemy(EnemyType enemy_type);
		EnemyType getRandomEnemyType();

		void updateSpawnTimer();
		void processEnemySpawn();

		void destroy();
		void destroyFlaggedEnemies();

	public:
		EnemyService();
		 ~EnemyService();

		void initialize();
		void update();
		void render();

		void reset();

		EnemyController* spawnEnemy();
		void destroyEnemy(EnemyController* enemy_controller);
	};
}