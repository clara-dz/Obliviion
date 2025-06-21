#include "EmoBoy.h"
#include "Inimigo.h"

EmoBoy::EmoBoy(int x, int y, int speed, const sf::Texture& texture)
: Inimigo(x, y, speed) {
sprite.setTexture(texture);
nivelMaldade = 2;
sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
startFalling();
numVidas = 2;
}

void EmoBoy::executar(float deltaTime) {
    
    applyGravity(deltaTime);
    sprite.move(velocityX * deltaTime, 0.f);
}