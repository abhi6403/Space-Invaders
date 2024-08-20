#pragma once

#include <vector>
#include "../../Header/Entity/EntityConfig.h"

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	private:
		std::vector<EnemyController*> enemy_list;
		std::vector<EnemyController*> flagged_enemy_list;
		const float spawn_interval = 2.0f;
		float spawn_timer;

		void updateSpawnTimer();
		void processEnemySpawn();
		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType enemy_type);

		void destroyFlaggedEnemies();
		void destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();
		void reset();

		EnemyController* SpawnEnemy();
		void destroyEnemy(EnemyController* enemy_controller);
	};
}