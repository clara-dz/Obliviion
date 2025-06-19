#pragma once

#include "Entidade.h"

enum class Dono { Jogador, Inimigo };

class Projetil : public Entidade {
    protected:
        sf::Sprite sprite;
        sf::Vector2f velocidade;
        Dono dono;
        bool ativo = true;

    public:
        Projetil(const sf::Texture& tex, const sf::Vector2f& pos, const sf::Vector2f& vel, Dono dono)
            : velocidade(vel), dono(dono) {
            sprite.setTexture(tex);
            sprite.setPosition(pos);
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