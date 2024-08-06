#include"../../Header/Bullet/BulletView.h"
#include"../../Header/Bullet/BulletController.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Global/Config.h"
#include"../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
	using namespace Global;

	BulletView::BulletView()
	{

    }

	BulletView::~BulletView()
	{

	}

	void BulletView::initialize(BulletController* controller)
	{
		bullet_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImage(bullet_controller->getBulletType());
	}

	void BulletView::initializeImage(BulletType type)
	{
		switch (type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			if (bullet_texture.loadFromFile(Config::laser_bullet_texture_path))
			{
				bullet_sprite.setTexture(bullet_texture);
				scaleImage();
			}
			break;
		case::Bullet::BulletType::FROST_BULLET:
			if(bullet_texture.loadFromFile(Config::frost_beam_texture_path))
			{
				bullet_sprite.setTexture(bullet_texture);
				scaleImage();
			}
			break;
		case::Bullet::BulletType::TORPEDO:
			if (bullet_texture.loadFromFile(Config::torpedoe_texture_path))
			{
				bullet_sprite.setTexture(bullet_texture);
				scaleImage();
			}
			break;

		}
	}

	void BulletView::scaleImage()
	{
		bullet_sprite.setScale(
			static_cast<float>(bullet_sprite_width) / bullet_sprite.getTexture()->getSize().x,
			static_cast<float>(bullet_sprite_height) / bullet_sprite.getTexture()->getSize().y
		);
	}

	void BulletView::update()
	{
		bullet_sprite.setPosition(bullet_controller->getProjectilePosition());
	}

	void BulletView::render()
	{
		game_window->draw(bullet_sprite);
	}
}