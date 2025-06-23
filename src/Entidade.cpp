#include "Entidade.h"

Entidade::Entidade() : x(0), y(0), isVisible(true) {}              //a classe tem duas funções inicializadoras
Entidade::Entidade(int x, int y) : x(x), y(y), isVisible(true) {}

void Entidade::desenhar(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!isVisible) return;
    target.draw(sprite, states);
}

void Entidade::renderizar(sf::RenderWindow& window) {
    if (isVisible)
        window.draw(sprite);
}

void Entidade::setSprite(const sf::Texture& texture) {
    sprite.setTexture(texture);
}
        