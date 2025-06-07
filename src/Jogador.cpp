#include "Jogador.h"


Jogador::Jogador(const sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(375.f, 275.f);
}

void Jogador::update() {
    // Horizontal movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        sprite.move(-speed, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        sprite.move(speed, 0.f);

    // Jump
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isOnGround) {
        velocityY = -10.f;
        isOnGround = false;
    }

    // Apply gravity
    applyGravity();
}

void Jogador::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Jogador::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states); // Now this function is implemented, SFML can call it to render the sprite
}