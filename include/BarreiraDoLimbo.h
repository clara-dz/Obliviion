#pragma once

#include "Obstaculo.h"
#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace Entidades {
    namespace Obstaculos {

        class BarreiraDoLimbo : public Obstaculo {
        private:
            float largura;

        public:
            BarreiraDoLimbo(const sf::Texture& texture, float x, float y);

            void obstaculizar(Jogador& jogador) override;
            void executar(float deltaTime) override;
            bool temLarguraMinima(float valor) const;
        };

    }
}