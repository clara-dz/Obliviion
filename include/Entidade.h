#pragma once

#include <SFML/Graphics.hpp>

class Entidade {
    protected:
        sf::Sprite sprite;
        int x, y; // Position of the entity
        bool isVisible; // Visibility state of the entity (could be useful for obstacles or hidden elements)

    public:
        // Constructors
        Entidade() : x(0), y(0), isVisible(true) {}
        Entidade(int x, int y) : x(x), y(y), isVisible(true) {}

        // Virtual destructor for proper cleanup of derived classes
        virtual ~Entidade() {}
        
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            target.draw(sprite, states);
        }
        
        // Getter and setter for position
        int getX() const { return x; }
        int getY() const { return y; }
        void setX(int newX) { x = newX; }
        void setY(int newY) { y = newY; }

        // Virtual methods (could be overridden by subclasses)
        virtual void update() = 0; // For updating entity states (used for player/enemy movements, etc.)
        virtual void render(sf::RenderWindow &window) {
            if (isVisible) window.draw(sprite);
        }

        // Virtual method for handling collisions or interactions (platforms, obstacles, etc.)
        virtual void handleCollision(Entidade& other) = 0;

        // Method to set the sprite (can be reused for any entity type)
        void setSprite(const sf::Texture &texture) {
            sprite.setTexture(texture);
        }

        // Additional common methods can be added as needed (like visibility toggling, animations, etc.)
};
