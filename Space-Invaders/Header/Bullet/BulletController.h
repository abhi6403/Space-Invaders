#pragma once
#include"../../Header/Projectile/IProjectile.h"
#include"../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
	class BulletView;
	class BulletModel;
	enum class BulletType;

	class BulletController :public Projectile::IProjectile
	{
	protected:
		BulletView* bullet_view;
		BulletModel* bullet_model;

		void updateProjectilePosition() override;

		void moveUP();
		void moveDown();
		void handleOutOfBounds();

	public:
		BulletController(BulletType type);
		virtual ~BulletController() override;
		void initialize(sf::Vector2f position, Bullet::MovementDrirection direction)override;
		void update() override;
		void render() override;

		sf::Vector2f getProjectilePosition() override;
		BulletType getBulletType();
	};
}
