#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
    class PlayerController;

    class PlayerService
    {

    private:

        PlayerController* player_controller;

    public:

        PlayerService();
        ~PlayerService();

        void initialize();
        void update();
        void render();
    };
}

