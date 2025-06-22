#include "EmoGirl.h"

EmoGirl::EmoGirl(int x, int y, int speed, const sf::Texture& texture)
        : Inimigo(x, y, speed) {
        sprite.setTexture(texture);
        nivelMaldade = 1;  //nível mais baixo de maldade
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        startFalling();
    }

void EmoGirl::executar(float deltaTime) {
        applyGravity(deltaTime);
        sprite.move(-speed * deltaTime, 0.f); // moves left slowly
        // sprite.move(velocityX * deltaTime, 0.f);
}

