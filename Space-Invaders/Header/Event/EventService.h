#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event
{
	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED,
	};
	class EventService
	{
	private:
		sf::Event game_event;
		sf::RenderWindow* game_window;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();

		ButtonState left_mouse_button_state;
		ButtonState right_mouse_button_state;
		ButtonState left_arrow_button_state;
		ButtonState right_arrow_button_state;
		ButtonState A_button_state;
		ButtonState D_button_state;

		void updateMouseButtonState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);
		void updateKeyboardButtonState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button);

	public:
		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvents();
		bool pressedEscapeKey();
		bool isKeyboardEvent();
		bool pressedLeftKey();
		bool pressedRightKey();
		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();
		bool pressedAKey();
		bool pressedDKey();

	};
}
