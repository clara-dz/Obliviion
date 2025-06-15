#pragma once
#include "Inimigo.h"

class InimigoFraco : public Inimigo {
public:
    InimigoFraco(int x, int y, int speed, const sf::Texture& texture)
        : Inimigo(x, y, speed) {
        sprite.setTexture(texture);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        startFalling();
    }

    void executar(float deltaTime) override {
        // Simple patrolling logic (placeholder)
        applyGravity(deltaTime);
        sprite.move(0.f, 0.f); // moves left slowly
        // sprite.move(-speed * deltaTime, 0.f); // moves left slowly
    }

    void render(sf::RenderWindow& window) override {
        window.draw(sprite);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(sprite, states);
    }

    void atacar(Jogador& jogador) override {
        // Simple attack logic (e.g., proximity-based damage)
    }

    void handleCollision(Entidade& other) override {
        // Define reaction to collisions
    }
};
