#include"../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include"../../Header/Graphic/GraphicService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Graphic;

	GameplayView::GameplayView()
	{

	}

	GameplayView::~GameplayView()
	{

	}

	void GameplayView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeBackGroundSprite();
	}

	void GameplayView::initializeBackGroundSprite()
	{
		if (background_texture.loadFromFile(background_texture_path))
		{
			background_sprite.setTexture(background_texture);
			scaleBackGroundSprite();
		}
	}

	void GameplayView::scaleBackGroundSprite()
	{
		background_sprite.setScale(
			static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}

	void GameplayView::update()
	{

	}

	void GameplayView::render()
	{
		game_window->draw(background_sprite);
	}
}