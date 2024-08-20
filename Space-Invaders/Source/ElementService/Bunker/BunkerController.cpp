#include "../../Header/Elements/Bunker/BunkerController.h"
#include "../../Header/Elements/Bunker/BunkerView.h"
#include "../../../Header/Bullet/BulletController.h"
#include "../../../Header/Entity/EntityConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../../Header/Bullet/BulletConfig.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Bullet;
		using namespace Entity;
		using namespace Global;
		BunkerController::BunkerController()
		{
			bunker_view = new BunkerView();
		}

		BunkerController::~BunkerController()
		{
			delete(bunker_view);
		}

		void BunkerController::initialize(BunkerData data)
		{
			bunker_data = data;
			bunker_view->initialize(this);
		}

		void BunkerController::update()
		{
			bunker_view->update();
		}

		void BunkerController::render()
		{
			bunker_view->render();
		}

		sf::Vector2f BunkerController::getBunkerPosition()
		{
			return bunker_data.position;;
		}

		void BunkerController::onCollision(ICollider* other_collider)
		{
			BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

			if (bullet_controller && bullet_controller->getBulletType() == BulletType::TORPEDO)
			{
				ServiceLocator::getInstance()->getElementService()->destroyBunker(this);
			}
		}

		const sf::Sprite& BunkerController::getColliderSprite()
		{
			return bunker_view->getBunkerSprite();
		}



	}

}
