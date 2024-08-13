#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include"../../Header/UI/UIElement/TextView.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace UIElement;
	using namespace Interface;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
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

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller;

		default:
			return nullptr;;
		}
	}

	void UIService::destory()
	{
		delete(main_menu_controller);
	}
}
