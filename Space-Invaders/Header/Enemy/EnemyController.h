#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;
    
    enum class EnemyType;
    enum class EnemyState;

    class EnemyController
    {
    protected:

        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        virtual void move() = 0;
        //void moveLeft();
        //void moveRight();
        //void moveDown();

        sf::Vector2f getRandomInitialPosition();
        void handleOutOfBounds();

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void initialize();
        void update();
        void render();

        sf::Vector2f getEnemyPosition();
        EnemyState getEnemyState();
        EnemyType getEnemyType();
    };
}