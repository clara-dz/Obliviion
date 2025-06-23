#include "ChamaDeHades.h"

Entidades::Obstaculos::ChamaDeHades::ChamaDeHades(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

Entidades::Obstaculos::ChamaDeHades::~ChamaDeHades(){}

void Entidades::Obstaculos::ChamaDeHades::obstaculizar(Jogador& jogador) {
    if (jogador.isAlive && danoso) {
        jogador.tomarDano(danosidade);
        std::cout << "Jogador atingido pela Chama de Hades! Dano: " << danosidade << std::endl;
    }
}

void Entidades::Obstaculos::ChamaDeHades::executar(float deltaTime) {}


