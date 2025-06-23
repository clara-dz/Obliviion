#pragma once

#include "Entidade.h"
#include <nlohmann/json.hpp>


using json = nlohmann::json;

enum class Dono { Jogador, Inimigo };

namespace Entidades {
    class Projetil : public Entidade {
        protected:        
            bool ativo = true;
            Dono dono;
            sf::Vector2f velocidade;
            float tempoDeVida; // seconds

        public:
            Projetil(const sf::Texture& tex, const sf::Vector2f& pos, const sf::Vector2f& vel, Dono dono, float vida = 50.f)
                : Entidade(static_cast<int>(pos.x), static_cast<int>(pos.y)), velocidade(vel), dono(dono), tempoDeVida(vida) {
                sprite.setTexture(tex);        // inherited from Entidade
                sprite.setPosition(pos);       // sets initial position
            }
            ~Projetil() = default;

            void executar(float deltaTime) override;
            json salvar();

            sf::FloatRect getBounds() const;

            Dono getDono() const;
            bool estaAtivo() const;
            void desativar();
    };
}