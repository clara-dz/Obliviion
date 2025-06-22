#pragma once
#include "Obstaculo.h"
#include <iostream>

class ChamaDeHades : public Obstaculo {

    private:
        short int danosidade = 2;

    public:
        ChamaDeHades(const sf::Texture& texture, float x, float y);
        
        ~ChamaDeHades();

        void obstaculizar(Jogador& jogador) override;

        void executar(float deltaTime) override;

    };