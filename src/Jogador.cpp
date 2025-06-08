#include "Jogador.h"
#include <iostream>


Jogador::Jogador(const sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(375.f, 275.f);
}

void Jogador::update(float deltaTime) {
    if (knockbackTimer > 0.f) {
        knockbackTimer -= deltaTime;
    } else {
        knockbackTimer = 0.f;
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            velocityX = -speed;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            velocityX = speed;
    }

    sprite.move(velocityX * deltaTime, 0.f);

    velocityX *= 0.9f;
    if (std::abs(velocityX) < 1.f) velocityX = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isOnGround) {
        velocityY = -300.f;  // higher initial jump impulse (pixels per second)
        isOnGround = false;
    }

    applyGravity(deltaTime);
}

void Jogador::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Jogador::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states); // Now this function is implemented, SFML can call it to render the sprite
}