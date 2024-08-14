#include "../../header/Player/PlayerModel.h"

namespace Player
{
	PlayerModel::PlayerModel()
	{

	}

	PlayerModel::~PlayerModel()
	{

	}

	void PlayerModel::initialize()
	{
		reset();
	}

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		player_position = initial_player_position;
		player_score = 0;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return player_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		player_position = position;
	}

	int PlayerModel::getPlayeScore()
	{
		return player_score;
	}

	void PlayerModel::setPlayerScore(int score)
	{
		player_score = score;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}

	Entity::EntityType PlayerModel::getOwnerEntityType()
	{
		return owner_type;
	}
}