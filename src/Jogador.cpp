#include "Jogador.h"
#include <iostream>


Jogador::Jogador(const sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(375.f, 275.f);
}

void Jogador::executar(float deltaTime) {
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
        std::cout << "Jumping" << std::endl;

        velocityY = jumpStrength;
        isOnGround = false;
    }

    if (isFlashing && flashClock.getElapsedTime().asSeconds() > flashDuration) {

        sprite.setColor(sf::Color::Red);  // Reset to normal
        isFlashing = false;
    }

    applyGravity(deltaTime);
}

void Jogador::renderizar(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Jogador::desenhar(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states); // Now this function is implemented, SFML can call it to renderizar the sprite
}