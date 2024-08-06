#pragma once
#include<SFML/Graphics.hpp>

namespace Bullet
{
	class BulletController;
	enum class BulletType;

	class BulletView
	{
	private:
		const float bullet_sprite_width = 18.f;
		const float bullet_sprite_height = 18.f;

		sf::RenderWindow* game_window;
		sf::Texture bullet_texture;
		sf::Sprite bullet_sprite;

		BulletController* bullet_controller;

		void initializeImage(BulletType type);
		void scaleImage();

	public:
		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();

	};
}