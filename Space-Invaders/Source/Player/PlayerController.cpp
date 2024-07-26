#include "../../Header/Player/PlayerContoller.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include<algorithm>

namespace Player
{
	using namespace Global;
	PlayerController::PlayerController()
	{
		player_view = new PlayerView();
		player_model = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete(player_view);
		delete(player_model);
	}
	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
	}

	void PlayerController::update()
	{
		processPlayerInput();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	void PlayerController::processPlayerInput()
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
		{
			moveLeft();
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
		{
			moveRight();
		}
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x -= player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}
}