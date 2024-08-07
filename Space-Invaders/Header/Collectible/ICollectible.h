#pragma once
#include<SFML/System/Vector2.hpp>

namespace Collectible
{
	class ICollectible
	{
	public:
		virtual void onCollected() = 0;
		virtual void initialize(sf::Vector2f position) = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		virtual sf::Vector2f getCollectiblePosition() = 0;

		virtual ~ICollectible() {};
	};


}