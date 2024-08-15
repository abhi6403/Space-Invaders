#pragma once
#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include"../../Header/UI/Interface/IUIController.h"
#include"../../Header/UI/GameplayUI/GameplayUIController.h"

namespace UI
{
	class UIService
	{
	private:

		MainMenu::MainMenuUIController* main_menu_controller;
		GameplayUI::GameplayUIController* gameplayUIController;
		


		void createControllers();
		void initializeControllers();

		Interface::IUIController* getCurrentUIController();

		void destory();


	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();

	};
}
