#include"../../Header/Bullet/BulletService.h"
#include"../../Header/Bullet/BulletController.h"
#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Entity/EntityConfig.h"
#include"../../Header/Projectile/IProjectile.h"
#include"../../Header/Bullet/Controllers/FrostBulletController.h"
#include"../../Header/Bullet/Controllers/LaserBulletController.h"
#include"../../Header/Bullet/Controllers/TorpedoeController.h"
#include"../../Header/Collision/ICollider.h"
#include"../../Header/Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Global;
	using namespace Collision;
	using namespace Entity;
	using namespace Projectile;

	BulletService::BulletService()
	{
		
	}

	BulletService::~BulletService()
	{
		destroy();
	}

	void BulletService::initialize()
	{
		bullet_list.clear();
		flagged_bullet_list.clear();
	}

	void BulletService::update()
	{
		
		
		for (Projectile::IProjectile* bullet : bullet_list)
			bullet->update();
		destroyFlaggedBullets();
	}

	void BulletService::render()
	{
		
		for (Projectile::IProjectile* bullet : bullet_list)
			 bullet->render();
		
	}

	BulletController* BulletService::createBullet(BulletType bullet_type,EntityType owner_type)
	{
	
		switch (bullet_type)
		{
		case Bullet::BulletType::LASER_BULLET:
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET,owner_type);

		case Bullet::BulletType::TORPEDO:
			return new TorpedoController(Bullet::BulletType::TORPEDO, owner_type);

		case Bullet::BulletType::FROST_BULLET:
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET, owner_type);
	
		}
	}

	bool BulletService::isValidBullet(int index_i, std::vector<Projectile::IProjectile*>& bullet_list)
	{
		
		return index_i >= 0 && index_i < bullet_list.size() && bullet_list[index_i] != nullptr;
		
	}

	void BulletService::destroyFlaggedBullets()
	{
		
		for (int i = 0; i < flagged_bullet_list.size(); i++)
		{
			if (!isValidBullet(i, flagged_bullet_list)) continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_bullet_list[i]));
			delete (flagged_bullet_list[i]);
		}
		flagged_bullet_list.clear();
	}

	void BulletService::destroy()
	{
		
		for (int i = 0; i < bullet_list.size(); i++)
		{
			if (!isValidBullet(i, bullet_list)) continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(bullet_list[i]));
			delete (bullet_list[i]);
		}
		bullet_list.clear();
	}

	BulletController* BulletService::spawnBullet(BulletType bullet_type,EntityType owner_type, sf::Vector2f position, MovementDirection direction)
	{
		
		BulletController* bullet_controller = createBullet(bullet_type,owner_type);
		bullet_controller->initialize(position, direction);

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(bullet_controller));
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		/*if (std::find(flagged_bullet_list.begin(), flagged_bullet_list.end(), bullet_controller) == flagged_bullet_list.end())
		{
			flagged_bullet_list.push_back(bullet_controller);
			bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
		}*/
	}

	void BulletService::reset()
	{
		destroy();
	}
}