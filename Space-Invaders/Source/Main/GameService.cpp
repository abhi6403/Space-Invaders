#include "../../Header/Main/Gameservice.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/UI/UIService.h"

namespace Main
{
	using namespace Global;
	using namespace Graphic;
	using namespace Event;
	using namespace UI;

	GameState GameService::current_state = GameState::BOOT;

	GameService::GameService()
	{
		service_locator = nullptr;
	}

	GameService::~GameService()
	{
		destroy();
	}

	void GameService::ignite()
	{
		service_locator = ServiceLocator::getInstance();
		initialize();
	}

	void GameService::initialize()
	{
		service_locator->initialize();
		initializeVariables();
		showSplashScreen();
	}

	void GameService::showSplashScreen()
	{
		setGameState(GameState::SPLASH_SCREEN);
		ServiceLocator::getInstance()->getUIService()->showScreen();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	void GameService::destroy()
	{
		
	}

	void GameService::update()
	{
		service_locator->getEventService()->processEvents();
		service_locator->update();
	}

	void GameService::render()
	{
		game_window->clear();
		service_locator->render();
		game_window->display();
	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

	void GameService::setGameState(GameState new_state)
	{
		current_state = new_state;
	}

	GameState GameService::getGameState()
	{
		return current_state;
	}
}