#include"../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;

	EnemyView::EnemyView()
	{

	}

	EnemyView::~EnemyView()
	{

	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeEnemySprite();
	}

	void EnemyView::initializeEnemySprite()
	{
		if (enemy_texture.loadFromFile(enemy_texture_path))
		{
			enemy_sprite.setTexture(enemy_texture);
			scaleEnemySprite();
		}
	}

	void EnemyView::scaleEnemySprite()
	{
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