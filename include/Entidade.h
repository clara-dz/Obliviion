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

        Entidade();           //a classe tem duas funções inicializadoras
        Entidade(int x, int y);
        
        virtual ~Entidade() {}

        virtual void executar(float deltaTime) override = 0;

        void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override;

        void renderizar(sf::RenderWindow& window) override;

        void setSprite(const sf::Texture& texture);
};
