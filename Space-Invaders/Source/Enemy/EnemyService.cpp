#include "../../Header/Enemy/EnemyController.h"
#include "../../Header//Enemy/EnemyService.h"
#include"../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyService::EnemyService()
	{
		enemy = nullptr;
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		spawnEnemy();
	}

	void EnemyService::update()
	{
		enemy->update();
	}
	void EnemyService::render()
	{
		enemy->render();
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		enemy = new EnemyController();
		enemy->initialize();

		return enemy;
	}

	void EnemyService::destroy()
	{
		delete(enemy);
	}
}