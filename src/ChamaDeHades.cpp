#include "ChamaDeHades.h"

ChamaDeHades::ChamaDeHades(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

ChamaDeHades::~ChamaDeHades() {}

void ChamaDeHades::obstaculizar(Jogador& jogador) {
    float knockbackSpeed = 500.f;

    jogador.setVelocityX(-1 * knockbackSpeed*danosidade);
    jogador.setVelocityY(-15.f);
    jogador.setKnockbackTimer(30.f);
}

void ChamaDeHades::executar(float deltaTime) {}


