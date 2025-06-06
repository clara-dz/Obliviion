#pragma once
#include <SFML/Graphics.hpp>

class Personagem : public sf::Drawable {
    public:
        virtual ~Personagem() = default;

        virtual void update() = 0;
        virtual void render(sf::RenderWindow& window) = 0;  

        sf::Sprite getSprite() { return sprite; }
    
    protected:
        sf::Sprite sprite;
};
