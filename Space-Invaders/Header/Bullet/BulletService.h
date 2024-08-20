#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	enum class BulletType;
	enum class MovementDirection;
	class BulletController;

	class BulletService
	{
	private:
		std::vector<Projectile::IProjectile*> bullet_list;
		std::vector<Projectile::IProjectile*> flagged_bullet_list;

		BulletController* createBullet(BulletType type, Entity::EntityType owner_type);

		void destroy();

		bool isValidBullet(int index_i, std::vector<Projectile::IProjectile*>& bullet_list);
		void destroyFlaggedBullets();

	public:
		BulletService();
		virtual ~BulletService();

		void initialize();
		void update();
		void render();
		void reset();

		BulletController* spawnBullet(BulletType bullet_type, Entity::EntityType owner_type, sf::Vector2f position, MovementDirection direction);
		void destroyBullet(BulletController* bullet_controller);

	};
}