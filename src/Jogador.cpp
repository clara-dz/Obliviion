#include "Jogador.h"


Jogador::Jogador(const sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(375.f, 275.f);
}

void Jogador::update(float deltaTime) {
    // Horizontal movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        sprite.move(-speed * deltaTime, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        sprite.move(speed * deltaTime, 0.f);

    // Jumping
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isOnGround) {
        velocityY = -300.f;  // higher initial jump impulse (pixels per second)
        isOnGround = false;
    }

    // Gravity
    applyGravity(deltaTime);
}

void Jogador::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Jogador::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states); // Now this function is implemented, SFML can call it to render the sprite
}