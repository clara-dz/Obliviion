#include "Entidade.h"

Entidades::Entidade::Entidade() : x(0), y(0), isVisible(true) {}              //a classe tem duas funções inicializadoras
Entidades::Entidade::Entidade(int x, int y) : x(x), y(y), isVisible(true) {}

void Entidades::Entidade::desenhar(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!isVisible) return;
    target.draw(sprite, states);
}

void Entidades::Entidade::renderizar(sf::RenderWindow& window) {
    if (isVisible)
        window.draw(sprite);
}

void Entidades::Entidade::setSprite(const sf::Texture& texture) {
    sprite.setTexture(texture);
}
        