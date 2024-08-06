#include"../../Header/Bullet/BulletService.h"
#include"../../Header/Bullet/BulletController.h"
#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Bullet/Controllers/FrostBulletController.h"
#include"../../Header/Bullet/Controllers/LaserBulletController.h"
#include"../../Header/Bullet/Controllers/TorpedoeController.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;

	BulletService::BulletService()
	{

	}

	BulletService::~BulletService()
	{
		destory();
	}

	void BulletService::initialize()
	{

	}

	void BulletService::update()
	{
		for (int i = 0;i < bullet_list.size();i++)bullet_list[i]->update();
	}

	void BulletService::render()
	{
		for (int i = 0;i < bullet_list.size();i++)bullet_list[i]->render();
	}

	BulletController* BulletService::createBullet(BulletType bullet_type)
	{
		switch (bullet_type)
		{
		case Bullet::BulletType::LASER_BULLET:
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET);

		case Bullet::BulletType::TORPEDO:
			return new TorpedoController(Bullet::BulletType::TORPEDO);

		case Bullet::BulletType::FROST_BULLET:
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET);
	
		}
	}

	void BulletService::destory()
	{
		for (int i = 0;i < bullet_list.size();i++)delete(bullet_list[i]);
	}

	BulletController* BulletService::spwanBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction)
	{
		BulletController* bullet_controller = createBullet(bullet_type);

		bullet_controller->initialize(position, direction);
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::destoryBullet(BulletController* bullet_controller)
	{
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
		delete(bullet_controller);
	}
}