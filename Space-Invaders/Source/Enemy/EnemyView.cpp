#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;

	EnemyView::EnemyView() { }

	EnemyView::~EnemyView() { }

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeEnemySprite();
	}

	void EnemyView::initializeEnemySprite()
	{
		if (enemy_texture.loadFromFile(enemy_texture_path)) //check if the texture loaded
		{
			enemy_sprite.setTexture(enemy_texture); //set the sprite
			scaleEnemySprite(); // call the method to scale the sprite
		}
	}

	void EnemyView::scaleEnemySprite()
	{
		// method to scale the Sprite according to our set dimensions. Don't worry about the static_cast, that will be discussed later.
		enemy_sprite.setScale(
			static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
		);
	}

	void EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}
}