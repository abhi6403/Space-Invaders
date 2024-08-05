#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/Elements/Bunker/BunkerModel.h"

namespace Elements
{
	namespace Bunker
	{
		class BunkerView;

		class BunkerController
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
		};
	}
	
}