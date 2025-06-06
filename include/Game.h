#pragma once

#include <SFML/Graphics.hpp>


class Game {
    public:
        Game();
        ~Game();
        void run();
        
    private:
        sf::RenderWindow window;
        sf::RectangleShape player;

        void processEvents();
        void update();
        void render();
};