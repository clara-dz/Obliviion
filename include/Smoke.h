#pragma once
#include "Obstaculo.h"
#include <iostream>

class Smoke : public Obstaculo {
    public:
        Smoke(const sf::Texture& texture, float x, float y) {
            sprite.setTexture(texture);
            sprite.setPosition(x, y);
        }

        void afetar(Jogador& jogador) override {
            jogador.reduzirVelocidade(0.8f);
        }

        void executar(float deltaTime) override {}
        void salva() override {}

    };