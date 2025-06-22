#pragma once

#include "Entidade.h"

enum class Dono { Jogador, Inimigo };

class Projetil : public Entidade {
    protected:        
        sf::Vector2f velocidade;
        Dono dono;
        bool ativo = true;
        
        float tempoDeVida; // seconds

    public:
        Projetil(const sf::Texture& tex, const sf::Vector2f& pos, const sf::Vector2f& vel, Dono dono, float vida = 50.f)
            : Entidade(static_cast<int>(pos.x), static_cast<int>(pos.y)), velocidade(vel), dono(dono), tempoDeVida(vida) {
            sprite.setTexture(tex);        // inherited from Entidade
            sprite.setPosition(pos);       // sets initial position
        }

        ~Projetil() = default;

        void executar(float deltaTime) override {
            if (!ativo) return;

            tempoDeVida -= deltaTime;
            if (tempoDeVida <= 0.f) {
                desativar();
                return;
            }

            sprite.move(velocidade * deltaTime);
        };

        void salvar() override {};
        void carregar() override {};

        sf::FloatRect getBounds() const {
            return sprite.getGlobalBounds();
        }
    
        Dono getDono() const { return dono; }
        bool estaAtivo() const { return ativo; }
        void desativar() { ativo = false; }
};