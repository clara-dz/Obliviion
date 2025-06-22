#pragma once

#include "Inimigo.h"

class EmoGirl : public Inimigo { // Inimigo Fraco
private:
    float raio;

public:
    EmoGirl(int x, int y, int speed, const sf::Texture& texture);
    void executar(float deltaTime) override;
    
    // {
    //     // Simple patrolling logic (placeholder)
    //     applyGravity(deltaTime);
    //     sprite.move(velocityX * deltaTime, 0.f);
    //     sprite.move(-speed * deltaTime, 0.f); // moves left slowly
    // }

    // void renderizar(sf::RenderWindow& window) override {
    //     window.draw(sprite);
    // }

    // void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override {
    //     target.draw(sprite, states);
    // }
};
