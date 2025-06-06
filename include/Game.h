#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"


class Game {
    public:
        Game();
        ~Game();
        void run();
        
    private:
        sf::RenderWindow window;
        Jogador player;

        void processEvents();
        void update();
        void render();
};