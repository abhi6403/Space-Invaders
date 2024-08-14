#pragma once
#include <vector>
#include"../../Header/Entity/EntityConfig.h"

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	private:

		const float spawn_interval = 3.f;

		std::vector<EnemyController*> enemy_list;
		float spawn_timer;

		EnemyController* createEnemy(EnemyType enemy_type);
		EnemyType getRandomEnemyType();

		void updateSpawnTimer();
		void processEnemySpawn();
		

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();


		EnemyController* spawnEnemy();
		void destroyEnemy(EnemyController* enemy_controller);
	};
}