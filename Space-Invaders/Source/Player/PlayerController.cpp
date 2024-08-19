#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Entity/EntityConfig.h"
#include"../../Header/Bullet/BulletController.h"
#include"../../Header/Enemy/EnemyController.h"
#include"../../Header/Powerup/PowerupController.h"
#include"../../Header/Main/GameService.h"
#include"../../Header/Sound/SoundService.h"
#include<algorithm>

namespace Player
{
	using namespace Global;
	using namespace Main;
	using namespace Event;
	using namespace Bullet;
	using namespace Time;
	using namespace Entity;
	using namespace Enemy;
	using namespace Powerup;
	using namespace Sound;
	using namespace Gameplay;

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
		switch (player_model->getPlayerState())
		{
		case::Player::PlayerState::ALIVE:
			processPlayerInput();
			break;

		case::Player::PlayerState::FROZEN:
			updateFreezDuration();
			break;
		}

		updatePowerupDuration();
		updateFireDuration();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	void PlayerController::reset()
	{
		player_model->reset();
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	const sf::Sprite& PlayerController::getColliderSprite()
	{
		return player_view->getPlayerSprite();
	}

	Entity::EntityType PlayerController::getOwnerEntityType()
	{
		return player_model->getOwnerEntityType();
	}

	void PlayerController::onCollision(ICollider* other_collider)
	{
		if (processPowerupCollision(other_collider))
			return;

		if (processBulletCollision(other_collider))
			return;

		processEnemyCollision(other_collider);
	}

	bool PlayerController::processBulletCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled())
			return false;

		BulletController* bullet_Controller = dynamic_cast<BulletController*>(other_collider);

		if (bullet_Controller && bullet_Controller->getOwnerEntityType() != EntityType::PLAYER)
		{
			if (bullet_Controller->getBulletType() == BulletType::FROST_BULLET)
			{
				player_model->setPlayerState(PlayerState::FROZEN);
				elapsed_freez_duration = player_model->freez_duration;
			}
			else
			{
				decreasePlayerlive();
				return true;
			}
		}
		return false;
	}

	bool PlayerController::processEnemyCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled())
			return false;

		EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);
		if (enemy_controller)
		{
			decreasePlayerlive();
			return true;
		}
		return false;
	}

	bool PlayerController::processPowerupCollision(ICollider* other_collider)
	{
		PowerupController* powerup_controller = dynamic_cast<PowerupController*>(other_collider);
		if (powerup_controller)
		{
			return true;
		}
		return false;
	}

	void PlayerController::updatePowerupDuration()
	{
		if (elapsed_shield_duration > 0)
		{
			elapsed_shield_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (elapsed_shield_duration <= 0)
				disableShield();
		}

		if (elapsed_rapid_fire_duration > 0)
		{
			elapsed_rapid_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (elapsed_rapid_fire_duration <= 0)
				disableRapidFire();
		}

		if (elapsed_tripple_laser_duration > 0)
		{
			elapsed_tripple_laser_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (elapsed_tripple_laser_duration <= 0)
				disableTrippleLaser();
		}
	}

	void PlayerController::freezPlayer()
	{
		player_model->setPlayerState(PlayerState::FROZEN);
		elapsed_freez_duration = player_model->freez_duration;
		player_view->setPlayerHighlight(true);
	}

	void PlayerController::enableShield()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_ENABLED);
		elapsed_shield_duration = player_model->shield_powerup_duration;
		player_model->setShieldState(true);
		player_view->setPlayerHighlight(false);
	}

	void PlayerController::disableShield()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_DISABLED);
		player_model->setShieldState(false);
		player_view->setPlayerHighlight(false);
	}

	void PlayerController::enableRapidFire()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_ENABLED);
		elapsed_rapid_fire_duration = player_model->rapid_fire_powerup_duration;
		player_model->setRapidFireState(true);
	}

	void PlayerController::disableRapidFire()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_DISABLED);
		player_model->setRapidFireState(false);
	}

	void PlayerController::enableTrippleLaser()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_ENABLED);
		elapsed_tripple_laser_duration = player_model->tripple_laser_powerup_duration;
		player_model->setTrippleFireState(true);
	}

	void PlayerController::disableTrippleLaser()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_DISABLED);
		player_model->setTrippleFireState(false);
	}

	void PlayerController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();
		
		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			moveLeft();
		}

		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			moveRight();
		}

		if (event_service->pressedLeftMouseButton()) processBulletFire();
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

	void PlayerController::updateFireDuration()
	{
		if (elapsed_fire_duration >= 0)
		{
			elapsed_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		}
	}

	void PlayerController::updateFreezDuration()
	{
		if (elapsed_freez_duration > 0)
		{
			elapsed_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (elapsed_freez_duration <= 0)
			{
				player_model->setPlayerState(PlayerState::ALIVE);
				player_view->setPlayerHighlight(true);
			}
		}
	}


	void PlayerController::processBulletFire()
	{
		if (elapsed_fire_duration > 0) return;

		if (player_model->isTrippleFireEnabled())
			fireBullet(true);

		else fireBullet();

		if (player_model->isRapidFireEnabled())
			elapsed_fire_duration = player_model->rapid_fire_cooldown_duration;

		else elapsed_fire_duration = player_model->fire_cooldown_duration;
	}

	void PlayerController::fireBullet(bool b_tripple_laser)
	{
		sf::Vector2f bullet_position = player_model->getPlayerPosition() + player_model->barrel_position_offset;
		fireBullet(bullet_position);

		if (b_tripple_laser)
		{
			fireBullet(bullet_position + player_model->second_weapon_position_offset);
			fireBullet(bullet_position + player_model->third_weapon_position_offset);
		}
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BULLET_FIRE);
	}

	void PlayerController::fireBullet(sf::Vector2f position)
	{
		
		ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
			player_model->getOwnerEntityType(), position, Bullet::MovementDirection::UP);
	}

	void PlayerController::decreasePlayerlive()
	{
		PlayerModel::player_lives -= 1;
		if (PlayerModel::player_lives <= 0)
		{
			reset();
		}
	}
}