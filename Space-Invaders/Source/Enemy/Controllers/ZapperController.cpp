#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include"../../Header/Bullet/BulletService.h"


namespace Enemy
{
    using namespace Global;
    using namespace Bullet;

    namespace Controller
    {
        ZapperController::ZapperController(EnemyType type) : EnemyController(type) { }

        ZapperController::~ZapperController() { }

        void ZapperController::initialize()
        {
            EnemyController::initialize(); 
            enemy_model->setMovementDirection(MovementDirection::DOWN);
            rate_of_fire = zapper_rate_of_fire;
        }

        void ZapperController::fireBullet()
        {
            ServiceLocator::getInstance()->getBulletService()->spwanBullet(BulletType::LASER_BULLET,
                enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
                Bullet::MovementDirection::DOWN);
        }
        
        void ZapperController::move()
        {
            
            switch (enemy_model->getMovementDirection())
            {
                
            case::Enemy::MovementDirection::LEFT:
                moveLeft();
                break;

                
            case::Enemy::MovementDirection::RIGHT:
                moveRight();
                break;

                
            case::Enemy::MovementDirection::DOWN:
                moveDown();
                break;
            }
        }

       
        void ZapperController::moveLeft()
        {
            
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            
            currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            
            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                
                enemy_model->setMovementDirection(MovementDirection::DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                
                enemy_model->setEnemyPosition(currentPosition);
            }
        }

        
        void ZapperController::moveRight()
        {
            
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            
            currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            
            if (currentPosition.x >= enemy_model->right_most_position.x)
            {
                
                enemy_model->setMovementDirection(MovementDirection::DOWN);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                
                enemy_model->setEnemyPosition(currentPosition);
            }
        }

        
        void ZapperController::moveDown()
        {
            
            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            
            currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            
            if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
            {
                
                if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x)
                {
                    
                    enemy_model->setMovementDirection(MovementDirection::RIGHT);
                }
                else
                {
                    
                    enemy_model->setMovementDirection(MovementDirection::LEFT);
                }
            }
            else
            {
                
                enemy_model->setEnemyPosition(currentPosition);
            }
        }
    }
}