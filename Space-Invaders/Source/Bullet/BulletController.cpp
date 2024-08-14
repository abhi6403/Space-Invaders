#include"../../Header/Bullet/BulletController.h"
#include"../../Header/Bullet/BulletView.h"
#include"../../Header/Bullet/BulletModel.h"
#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Player/PlayerController.h"
#include"../../Header/Enemy/EnemyController.h"
#include"../../Header/Elements/Bunker/BunkerController.h"


namespace Bullet
{
	using namespace Global;
	using namespace Entity;
	using namespace Player;
	using namespace Enemy;
	using namespace Element::Bunker;

	BulletController::BulletController(BulletType bullet_type,Entity::EntityType owner_type)
	{
		bullet_view = new BulletView();
		bullet_model = new BulletModel(bullet_type, owner_type);
	}

	BulletController::~BulletController()
	{
		delete(bullet_view);
		delete(bullet_model);
	}

	void BulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
		bullet_view->initialize(this);
		bullet_model->initialize(position, direction);
	}

	
	void BulletController::update()
	{
		updateProjectilePosition();
		bullet_view->update();
		handleOutOfBounds();
	}

	void BulletController::render()
	{
		bullet_view->render();
	}

	void BulletController::updateProjectilePosition()
	{
		switch (bullet_model->getMovementDirection())
		{
		case::Bullet::MovementDirection::UP:
			moveUP();
			break;

		case::Bullet::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void BulletController::moveUP()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y -= bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		bullet_model->setBulletPosition(currentPosition);
	}

	void BulletController::moveDown()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y += bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		bullet_model->setBulletPosition(currentPosition);
	}

	void BulletController::handleOutOfBounds()
	{
		sf::Vector2f bulletPosition = getProjectilePosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
			bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	sf::Vector2f BulletController::getProjectilePosition()
	{
		return bullet_model->getBulletPosition();
	}

	BulletType BulletController::getBulletType()
	{
		return bullet_model->getBulletType();
	}

	EntityType BulletController::getOwnerEntityType()
	{
		return bullet_model->getOwnerEntityType();
	}

	const sf::Sprite& BulletController::getColliderSprite()
	{
		return bullet_view->getBulletSprite();
	}

	void BulletController::onCollision(ICollider* other_collider)
	{
		processPlayerCollision(other_collider);
		processEnemyCollision(other_collider);
		processBunkerCollision(other_collider);
		processBulletCollision(other_collider);
	}

	void BulletController::processBulletCollision(ICollider* other_collider)
	{
		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

		if (bullet_controller)
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
	}

	void BulletController::processEnemyCollision(ICollider* other_collider)
	{
		EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);

		if (enemy_controller && getOwnerEntityType() != EntityType::ENEMY)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::processPlayerCollision(ICollider* other_collider)
	{
		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);

		if (player_controller && getOwnerEntityType() != EntityType::PLAYER)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::processBunkerCollision(ICollider* other_collider)
	{
		BunkerController* bunker_controller = dynamic_cast<BunkerController*>(other_collider);

		if (bunker_controller)
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
	}
}