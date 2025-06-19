#pragma once

#include "Entidade.h"

enum class Dono { Jogador, Inimigo };

class Projetil : public Entidade {
    protected:
        sf::Vector2f velocidade;
        Dono dono;
        bool ativo = true;

    public:
        Projetil(const sf::Texture& tex, const sf::Vector2f& pos, const sf::Vector2f& vel, Dono dono)
            : Entidade(static_cast<int>(pos.x), static_cast<int>(pos.y)), velocidade(vel), dono(dono) {
            sprite.setTexture(tex);        // inherited from Entidade
            sprite.setPosition(pos);       // sets initial position
        }

        ~Projetil() = default;

        void executar(float deltaTime) override {
            sprite.move(velocidade * deltaTime);
        };

        void salvar();

        sf::FloatRect getBounds() const {
            return sprite.getGlobalBounds();
        }
    
        Dono getDono() const { return dono; }
        bool estaAtivo() const { return ativo; }
        void desativar() { ativo = false; }
};