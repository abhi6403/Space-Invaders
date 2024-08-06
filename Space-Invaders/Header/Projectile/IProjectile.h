#pragma once
#include<SFML/System/Vector2.hpp>
#include"../../Header/Bullet/BulletConfig.h"

namespace Projectile
{
	enum class MovementDirection;

	class IProjectile
	{
	public:
		virtual void initialize(sf::Vector2fposition, Bullet::MovementDirection direction) = 0;
		virtual void update() = 0;
		virtual void render() = 0;

		virtual void updateProjectilePosition() = 0;
		virtual sf::Vector2f  getProjectilePosition() = 0;

		virtual ~IProjectile() {};
	};
}