#pragma once
#include"../../Header/UI/UIElement/AnimatedImageView.h"
#include"../../Header/UI/Interface/IUIController.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:

			const float logo_animation_duration = 2.0f;
			const float logo_width = 600.f;
			const float logo_height = 134.f;

			UIElement::AnimatedImageView* outscal_logo_view;

			void initializeOutscalLogo();
			void fadeInAnimationCallback();
			void fadeOutAnimationCallback();
			sf::Vector2f getLogoPosition();

		public:
			SplashScreenUIController();
			~SplashScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}