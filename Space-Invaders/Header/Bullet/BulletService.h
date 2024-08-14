#pragma once
#include<vector>
#include"SFML/System/Vector2.hpp"
#include"../../Header/Projectile/IProjectile.h"
#include"../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:

		std::vector<Projectile::IProjectile*>bullet_list;

		BulletController* createBullet(BulletType type,Entity::EntityType owner_type);
		void destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void initialize();
		void update();
		void render();

		BulletController* spwanBullet(BulletType bullet_type,Entity::EntityType owner_type, sf::Vector2f position, MovementDirection direction);
		void destroyBullet(BulletController* bullet_controller);
	};

}