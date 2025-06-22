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
            float knockbackSpeed = 500.f;

            jogador.setVelocityX(-1 * knockbackSpeed);
            jogador.setVelocityY(-15.f);
            jogador.setKnockbackTimer(30.f);
        }

        void executar(float deltaTime) override {}
    };