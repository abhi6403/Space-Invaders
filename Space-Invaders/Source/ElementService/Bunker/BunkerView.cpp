#include "../../Header/Elements/Bunker/BunkerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Elements/Bunker/BunkerController.h"
#include "../../Header/Global/Config.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;
		using namespace UI::UIElement;

		BunkerView::BunkerView()
		{
			createUIElements();
		}

		BunkerView::~BunkerView()
		{
			destroy();
		}

		void BunkerView::createUIElements()
		{
			bunker_image = new ImageView();
		}

		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			initializeImage();
		}

		void BunkerView::initializeImage()
		{
			bunker_image->initialize(getBunkerTexturePath(), bunker_sprite_width, bunker_sprite_height, bunker_controller->getBunkerPosition());
		}

		void BunkerView::update()
		{
			bunker_image->setPosition(bunker_controller->getBunkerPosition());
			bunker_image->update();
		}

		void BunkerView::render()
		{
			bunker_image->render();
		}


		sf::String BunkerView::getBunkerTexturePath()
		{
			return Config::bunker_texture_path;
		}

		void BunkerView::destroy()
		{
			delete(bunker_image);
		}

		const sf::Sprite& BunkerView::getBunkerSprite()
		{
			return bunker_image->getSprite();
		}
	}
}
