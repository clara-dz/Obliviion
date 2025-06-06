#pragma once

#include <SFML/Graphics.hpp>
#include "Fase.h"
#include "GardenOfEden.h"


class Game {
    public:
        Game();
        ~Game();
        void run();
        
    private:
        sf::RenderWindow window;

        Fase* currentLevel;

        void processEvents();
        void update();
        void render();
};