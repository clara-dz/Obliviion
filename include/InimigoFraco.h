#pragma once

#include "Inimigo.h"

class InimigoFraco : public Inimigo { //Nome: EmoGirl
private:
    float raio;

public:
    // void danificar(Jogador* p) override {};
    InimigoFraco(int x, int y, int speed, const sf::Texture& texture)
        : Inimigo(x, y, speed) {
        sprite.setTexture(texture);
        nivelMaldade = 1;
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        startFalling();
    }

    void executar(float deltaTime) override {
        // Simple patrolling logic (placeholder)
        applyGravity(deltaTime);
        sprite.move(velocityX * deltaTime, 0.f);
        // sprite.move(-speed * deltaTime, 0.f); // moves left slowly
    }

    // void renderizar(sf::RenderWindow& window) override {
    //     window.draw(sprite);
    // }

    // void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override {
    //     target.draw(sprite, states);
    // }
};
