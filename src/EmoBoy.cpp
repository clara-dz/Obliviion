#include "EmoBoy.h"

EmoBoy::EmoBoy(int x, int y, int speed, const sf::Texture& texture)
    : Inimigo(x, y, speed) {
    nivelMaldade = 2; //o dobro do inimigo fraco
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    startFalling();
    numVidas = 2;
    sprite.setTexture(texture);
}

void EmoBoy::executar(float deltaTime) {
    
    applyGravity(deltaTime);
    sprite.move(velocityX * deltaTime, 0.f);
}