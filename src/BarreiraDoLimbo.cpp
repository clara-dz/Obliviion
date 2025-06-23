#include "BarreiraDoLimbo.h"
#include <iostream>

using namespace Entidades::Obstaculos;

BarreiraDoLimbo::BarreiraDoLimbo(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    largura = sprite.getGlobalBounds().width;
}

void BarreiraDoLimbo::obstaculizar(Jogador& jogador) {
    float knockbackSpeed = 500.f;

    jogador.setVelocityX(-1 * knockbackSpeed);
    jogador.setVelocityY(-15.f);
    jogador.setKnockbackTimer(30.f);
}

bool BarreiraDoLimbo::temLarguraMinima(float valor) const {
    return largura >= valor;
}

void BarreiraDoLimbo::executar(float deltaTime) {
    // Barreira é estática, não precisa de lógica em tempo de execução.
}
