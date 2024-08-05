#include"../../Header/Elements/Bunker/BunkerController.h"
#include"../../Header/Elements/Bunker/BunkerView.h"

namespace Element
{
	namespace Bunker
	{
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
			return bunker_data.position;
		}
	}
}