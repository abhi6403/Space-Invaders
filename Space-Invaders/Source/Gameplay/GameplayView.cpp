#include"../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include"../../Header/Graphic/GraphicService.h"
#include"../../Header/Global/Config.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Graphic;
	using namespace UI::UIElement;

	GameplayView::GameplayView()
	{
		background_image = new ImageView();
	}

	GameplayView::~GameplayView()
	{
		delete(background_image);
	}

	void GameplayView::initialize()
	{
		initializeBackgroundImage();
	}

	void GameplayView::initializeBackgroundImage()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		background_image->initialize(Config::background_texture_path,
			game_window->getSize().x,
			game_window->getSize().y,
			sf::Vector2f(0, 0));
	}

	void GameplayView::update()
	{
		background_image->update();
	}

	void GameplayView::render()
	{
		background_image->render();
	}
}