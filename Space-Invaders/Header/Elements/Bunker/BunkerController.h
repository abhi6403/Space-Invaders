#pragma once

#include<SFML/Graphics.hpp>
#include "../../Header/Elements/Bunker/BunkerModel.h"
#include "../../Collision/ICollider.h"

namespace Element
{
	namespace Bunker
	{
		class BunkerView;

		class BunkerController : public Collision::ICollider
		{
		private:
			BunkerView* bunker_view;
			BunkerData bunker_data;

		public:
			BunkerController();
			~BunkerController();

			void initialize(BunkerData data);
			void update();
			void render();

			sf::Vector2f getBunkerPosition();

			const sf::Sprite& getColliderSprite() override;
			void onCollision(ICollider* other_collider) override;

		};
	}
}
