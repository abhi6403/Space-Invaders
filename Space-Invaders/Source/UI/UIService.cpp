#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include"../../Header/UI/UIElement/TextView.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace UIElement;
	using namespace Interface;
	using namespace GameplayUI;
	using namespace SplashScreen;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplayUIController = nullptr;
		splash_screen_ui_controller = nullptr;
		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		gameplayUIController = new GameplayUIController();
		splash_screen_ui_controller = new SplashScreenUIController();
	}

	UIService::~UIService()
	{
		destory();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
		gameplayUIController->initialize();
		splash_screen_ui_controller->initialize();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)ui_controller->show();
	}

	

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_ui_controller;

		case GameState::MAIN_MENU:
			return main_menu_controller;

		case GameState::GAMEPLAY:
			return gameplayUIController;

		default:
			return nullptr;
		}
	}

	void UIService::destory()
	{
		delete(main_menu_controller);
		delete(gameplayUIController);
		delete(splash_screen_ui_controller);
	}
}
