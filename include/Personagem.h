#pragma once
#include <SFML/Graphics.hpp>

class Personagem {
    public:
        virtual ~Personagem() = default;

        virtual void move() = 0;
        virtual void render(sf::RenderWindow& window) = 0;  
    
    protected:
        sf::RectangleShape shape;
};
