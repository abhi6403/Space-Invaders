#include"../../Header/UI/UIElement/ImageView.h"

namespace UI
{
	namespace UIElement
	{
		ImageView::ImageView() = default;

		ImageView::~ImageView() = default;

		void ImageView::initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position)
		{
			UIView::initialize();
			setTexture(texture_path);
			setScale(image_height, image_width);
			setPosition(position);

		}

		void ImageView::update()
		{
			UIView::update();
		}

		void ImageView::render()
		{
			UIView::render();

			if (ui_state == UIState::VISIBLE)
			{
				game_window->draw(image_sprite);
			}
		}

		void ImageView::setScale(float width, float height)
		{
			float scale_x = width / image_sprite.getTexture()->getSize().x;
			float scale_y = height / image_sprite.getTexture()->getSize().y;

			image_sprite.setScale(scale_x, scale_y);
		}

		void ImageView::setPosition(sf::Vector2f position)
		{
			image_sprite.setPosition(position);
		}

		void ImageView::setRotation(float rotation_angle)
		{
			image_sprite.setRotation(rotation_angle);
		}

		void ImageView::setImageAlpha(float alpha)
		{
			sf::Color color = image_sprite.getColor();
			color.a = alpha;
			image_sprite.setColor(color);
		}

		void ImageView::setCentreAlinged()
		{
			float x_position = (game_window->getSize().x / 2) - (image_sprite.getGlobalBounds().width / 2);
			float y_position = image_sprite.getGlobalBounds().getPosition().y;

			image_sprite.setPosition(x_position, y_position);
		}
	}
}