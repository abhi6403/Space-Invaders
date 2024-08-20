#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../Collision/ICollider.h"

namespace Enemy
{
	class EnemyView;
	class EnemyModel;

	enum class EnemyType;
	enum class EnemyState;

	class EnemyController : public Collision::ICollider
	{
	protected:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;

		float rate_of_fire = 3.0f;
		float elapsed_fire_duration = 0.0f;

		void virtual move() = 0;

		void updateFireTimer();
		void processBulletFire();
		virtual void fireBullet() = 0;

		sf::Vector2f getRandomInitialPosition();
		virtual void destroy();

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		void virtual initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
		void handleOutOfBounds();

		EnemyType getEnemyType();
		EnemyState getEnemyState();

		Entity::EntityType getOwnerEntityType();

		const sf::Sprite& getColliderSprite() override;
		virtual void onCollision(ICollider* other_collider) override;

	};
}