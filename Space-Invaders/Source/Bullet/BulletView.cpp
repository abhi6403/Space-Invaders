#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Bullet
{
	using namespace Global;
	using namespace UI::UIElement;

	BulletView::BulletView()
	{
		createUIElements();
	}

	BulletView::~BulletView()
	{
		destroy();
	}

	void BulletView::createUIElements()
	{
		bullet_image = new ImageView();
	}

	void BulletView::initialize(BulletController* controller)
	{
		bullet_controller = controller;
		initializeImage();
	}

	void BulletView::initializeImage()
	{
		bullet_image->initialize(getBulletTexturePath(), bullet_sprite_height, bullet_sprite_width, bullet_controller->getProjectilePosition());
	}

	void BulletView::update()
	{
		bullet_image->setPosition(bullet_controller->getProjectilePosition());
		bullet_image->update();
	}

	void BulletView::render()
	{
		bullet_image->render();
	}


	sf::String BulletView::getBulletTexturePath()
	{
		switch (bullet_controller->getBulletType())
		{
		case::Bullet::BulletType::FROST_BULLET:
			return BulletConfig::frost_beam_texture_path;

		case::Bullet::BulletType::LASER_BULLET:
			return BulletConfig::laser_bullet_texture_path;

		case::Bullet::BulletType::TORPEDO:
			return BulletConfig::torpedoe_texture_path;

		}
	}

	void BulletView::destroy()
	{
		delete(bullet_image);
	}

	const sf::Sprite& BulletView::getBulletSprite()
	{
		return bullet_image->getSprite();
	}
}

