#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"
#include <iostream>
#include <nlohmann/json.hpp>


using json = nlohmann::json;

class Entidade : public Ente {
    protected:
        sf::Sprite sprite; //tirar daqui pois já está em ENTE.H
        int x, y; //é passada para as classes filhas
        bool isVisible;

    public:

        Entidade() : x(0), y(0), isVisible(true) {}              //a classe tem duas funções inicializadoras
        Entidade(int x, int y) : x(x), y(y), isVisible(true) {}
        
        virtual ~Entidade() {}

        virtual void executar(float deltaTime) override = 0;
        virtual json salvar(json data) = 0;
        virtual void carregar() = 0;

        void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override {
            if (!isVisible) return;
            target.draw(sprite, states);
        }

        void renderizar(sf::RenderWindow& window) override {
            if (isVisible)
                window.draw(sprite);
        }

        void setSprite(const sf::Texture& texture) {
            sprite.setTexture(texture);
        }
};
