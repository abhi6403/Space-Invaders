#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include"../../Header/Elements/ElementService.h"
#include"../../Header/Sound/SoundService.h"
#include"../../Header/Bullet/BulletService.h"
#include"../../Header/Powerup/PowerupService.h"
#include"../../Header/Collision/CollisionService.h"
#include"../../Header/AnimationSystem/AnimationService.h"

namespace Global
{
    class ServiceLocator
    {
    private:

        Graphic::GraphicService* graphic_service;
        Event::EventService* event_service;
        Player::PlayerService* player_service;
        Time::TimeService* time_service;
        UI::UIService* ui_service;
        Enemy::EnemyService* enemy_service;
        Gameplay::GameplayService* gameplay_service;
        Element::ElementService* element_service;
        Sound::SoundService* sound_service;
        Bullet::BulletService* bullet_service;
        Powerup::PowerupService* powerup_service;
        Collision::CollisionService* collision_service;
        Animation::AnimationService* animation_service;

        ServiceLocator();
        ~ServiceLocator();

        // Private Methods:
        void createServices(); 			
        void clearAllServices(); 		

    public:
        // Public Methods:
        static ServiceLocator* getInstance();  

        void initialize(); 			
        void update(); 				
        void render(); 				

        // Methods to Get Specific Services: 
        Event::EventService* getEventService();   
        Graphic::GraphicService* getGraphicService();  
        Player::PlayerService* getPlayerService();
        Time::TimeService* getTimeService();
        UI::UIService* getUIService();
        Enemy::EnemyService* getEnemyService();
        Gameplay::GameplayService* getGameplayService();
        Element::ElementService* getElementService();
        Sound::SoundService* getSoundService();
        Bullet::BulletService* getBulletService();
        Powerup::PowerupService* getPowerupService();
        Collision::CollisionService* getCollisionService();
        Animation::AnimationService* getAnimationService();
    };
}
