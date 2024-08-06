#pragma once
#include<vector>
#include"SFML/System/Vector2.hpp"
#include"../../Header/Projectile/IProjectile.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:

		std::vector<Projectile::IProjectile*>bullet_list;

		BulletController* createBullet(BulletType bullet_type);
		void destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void initialize();
		void update();
		void render();

		BulletController* spwanBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction);
		void destroyBullet(BulletController* bullet_controller);
	};

}