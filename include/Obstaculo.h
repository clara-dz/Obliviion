#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include <nlohmann/json.hpp>


using json = nlohmann::json;

namespace Entidades {    
    namespace Obstaculos {
        class Obstaculo : public Entidades::Entidade {
        public:
            bool danoso = true;
            sf::RectangleShape hitbox; // Hitbox do obstáculo

            Obstaculo() = default;
            virtual ~Obstaculo() = default;

            sf::FloatRect getBounds() const {
                return sprite.getGlobalBounds();
            }

            virtual void obstaculizar(Jogador& jogador) = 0;

            virtual void executar(float deltaTime) override = 0;
        };
    }
}