#pragma once

namespace Bullet
{
	class BulletService
	{
	private:
		

	public:
		BulletService();
		~BulletService();

		void initialize();
		void update();
		void render();
	};

}