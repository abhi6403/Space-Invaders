#include "../../Header/Player/PlayerView.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView()
	{
		createUIElements();
	}

	PlayerView::~PlayerView()
	{
		destroy();
	}

	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller;
		initializeImage();
	}

	void PlayerView::createUIElements()
	{
		player_image = new ImageView();
		player_shield = new ImageView();
	}

	void PlayerView::initializeImage()
	{
		player_image->initialize(getPlayerTexturePath(), player_sprite_width, player_sprite_height, player_controller->getPlayerPosition());
		player_shield->initialize(Config::shield_texture_path, shield_sprite_width, shield_sprite_height, player_controller->getPlayerPosition());
		player_shield->setImageAlpha(100);
	}

	void PlayerView::update()
	{
		player_image->setPosition(player_controller->getPlayerPosition());
		player_image->update();

		player_shield->setPosition(sf::Vector2f(player_controller->getPlayerPosition().x - 30, player_controller->getPlayerPosition().y - 30));
		player_shield->update();
	}

	void PlayerView::render()
	{
		player_image->render();

		if (player_controller->isShieldEnabled())
		{
			player_shield->render();
		}

	}

	sf::String PlayerView::getPlayerTexturePath()
	{
		return Config::player_texture_path;
	}

	void PlayerView::destroy()
	{
		delete(player_image);
		delete(player_shield);
	}

	const sf::Sprite& PlayerView::getPlayerSprite()
	{
		return player_image->getSprite();
	}

	void PlayerView::setPlayerHighlight(bool b_highlight)
	{
		if (b_highlight) player_image->setImageAlpha(PlayerModel::invincible_player_alpha);
		else player_image->setImageAlpha(255);
	}

}