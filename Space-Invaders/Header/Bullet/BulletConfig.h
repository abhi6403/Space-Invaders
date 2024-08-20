#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
	enum class BulletType
	{
		LASER_BULLET,
		TORPEDO,
		FROST_BULLET,
	};

	enum class MovementDirection
	{
		UP,
		DOWN,
	};

	class BulletConfig
	{
	public:
		static const sf::String laser_bullet_texture_path;
		static const sf::String torpedoe_texture_path;
		static const sf::String frost_beam_texture_path;

		static sf::String getBulletTexturePath(BulletType bullet_type);
	};
}
