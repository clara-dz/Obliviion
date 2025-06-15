#pragma once

#include <SFML/Graphics.hpp>
#include "Fase.h"
#include "GardenOfEden.h"
#include "Menu.h"


class Game {
    public:
        Game();
        ~Game();
        void run();
        
    private:
        sf::RenderWindow window;
        Fase* currentLevel;
        sf::Clock clock;
        Menu* menu;
        sf::Font font;

        void processEvents();
        void executar();
        void render();
};