#pragma once
#include "Obstaculo.h"

class Smoke : public Obstaculo {
    public:
        Smoke(const sf::Texture& texture, float x, float y) {
            sprite.setTexture(texture);
            sprite.setPosition(x, y);
        }

        void afetar(Jogador& jogador) override {
            jogador.reduzirVelocidade(0.5f); // Reduz pela metade
        }

        void executar(float deltaTime) override {}
        void salva() override {}

    };