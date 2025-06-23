#include "ChamaDeHades.h"

ChamaDeHades::ChamaDeHades(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

ChamaDeHades::~ChamaDeHades(){}

void ChamaDeHades::obstaculizar(Jogador& jogador) {
    if (jogador.isAlive) {
        jogador.tomarDano(danosidade);
        std::cout << "Jogador atingido pela Chama de Hades! Dano: " << danosidade << std::endl;
    }
}

void ChamaDeHades::executar(float deltaTime) {}


