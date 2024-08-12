#pragma once
#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include"../../Header/UI/Interface/IUIController.h"
namespace UI
{

	class UIService
	{
	private:

		MainMenu::MainMenuUIController* main_menu_controller;
		Interface::IUIController* ui_controller;


		void createControllers();
		void initializeControllers();
		void getCurrentUIController();
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
