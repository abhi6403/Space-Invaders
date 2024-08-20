#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Bullet
{
	enum class BulletType;
	class BulletController;

	class BulletView
	{
	private:
		const float bullet_sprite_height = 18.0f;
		const float bullet_sprite_width = 18.0f;

		BulletController* bullet_controller;
		UI::UIElement::ImageView* bullet_image;

		void createUIElements();
		void initializeImage();
		sf::String getBulletTexturePath();
		void destroy();

	public:
		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();

		const sf::Sprite& getBulletSprite();
	};

}


