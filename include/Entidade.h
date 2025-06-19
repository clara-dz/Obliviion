#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"
#include <iostream>

class Entidade : public Ente {
    protected:
        sf::Sprite sprite;
        int x, y;
        bool isVisible;
        // ostream buffer;
        void salvarDataBuffer();

    public:
        // virtual void salvar() = 0;
        Entidade() : x(0), y(0), isVisible(true) {}
        Entidade(int x, int y) : x(x), y(y), isVisible(true) {}
        virtual ~Entidade() {}

        // These override the base Ente methods
        void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override {
            target.draw(sprite, states);
        }

        void renderizar(sf::RenderWindow& window) override {
            std::cerr << "Rendering Entidade at (" << x << ", " << y << ")" << std::endl;
            window.draw(sprite);
        }

        virtual void executar(float deltaTime) override = 0;

        // Position accessors
        int getX() const { return x; }
        int getY() const { return y; }
        void setX(int newX) { x = newX; }
        void setY(int newY) { y = newY; }

        void setSprite(const sf::Texture& texture) {
            sprite.setTexture(texture);
        }
};
