#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Element
{
    namespace Bunker
    {
        class BunkerController;

        class BunkerView
        {
        private:
            const float bunker_sprite_width = 80.f;
            const float bunker_sprite_height = 80.f;

            BunkerController* bunker_controller;

            UI::UIElement::ImageView* bunker_image;

            void createUIElements();
            void initializeImage();
            sf::String getBunkerTexturePath();
            void destroy();

        public:
            BunkerView();
            ~BunkerView();

            void initialize(BunkerController* controller);
            void update();
            void render();

            const sf::Sprite& getBunkerSprite();
        };
    }
}