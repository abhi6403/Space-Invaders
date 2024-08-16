#include "../../Header/UI/SplashScreenUI/SplashScreenUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace UI
{
    namespace SplashScreen
    {
        using namespace Main;
        using namespace Graphic;
        using namespace Global;
        using namespace UIElement;
        using namespace Sound;

        SplashScreenUIController::SplashScreenUIController()
        {
            outscal_logo_view = new ImageView();
        }

        SplashScreenUIController::~SplashScreenUIController()
        {
            delete (outscal_logo_view);
        }

        void SplashScreenUIController::initialize()
        {
            initializeOutscalLogo();
        }

        void SplashScreenUIController::update()
        {
            updateTimer();
            showMainMenu();
        }

        void SplashScreenUIController::render()
        {
            outscal_logo_view->render();
        }

        void SplashScreenUIController::initializeOutscalLogo()
        {
            sf::Vector2f position = getLogoPosition();
            outscal_logo_view->initialize(Config::outscal_logo_texture_path, logo_width, logo_height, position);

        }

        void SplashScreenUIController::showMainMenu()
        {
            if (elapsed_duration >= splash_screen_duration)
            {
                ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
                GameService::setGameState(GameState::MAIN_MENU);
            }

        }

        void SplashScreenUIController::updateTimer()
        {
            elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
        }

        sf::Vector2f SplashScreenUIController::getLogoPosition()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            float x_position = (game_window->getSize().x - logo_width) / 2.0f;
            float y_position = (game_window->getSize().y - logo_height) / 2.0f;

            return sf::Vector2f(x_position, y_position);
        }

        void SplashScreenUIController::show()
        {

        }
    }
}