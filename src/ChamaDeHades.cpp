#include "ChamaDeHades.h"

Obstaculos::ChamaDeHades::ChamaDeHades(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

Obstaculos::ChamaDeHades::~ChamaDeHades(){}

void Obstaculos::ChamaDeHades::obstaculizar(Jogador& jogador) {
    if (jogador.isAlive) {
        jogador.tomarDano(danosidade);
        std::cout << "Jogador atingido pela Chama de Hades! Dano: " << danosidade << std::endl;
    }
}

void Obstaculos::ChamaDeHades::executar(float deltaTime) {}


