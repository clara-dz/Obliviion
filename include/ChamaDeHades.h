#pragma once
#include "Obstaculo.h"
#include <iostream>

namespace Entidades {    
    namespace Obstaculos {
        class ChamaDeHades : public Obstaculo { //obs difícil

            private:
                short int danosidade = 2; //duas vezes mais danoso que obs médio

            public:
                ChamaDeHades(const sf::Texture& texture, float x, float y);

                ~ChamaDeHades();

                void obstaculizar(Jogador& jogador) override;

                void executar(float deltaTime) override;

            };
    }
}