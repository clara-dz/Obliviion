#include "Jogador.h"
#include "Projetil.h"
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
        bool upNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

        if (upNow && !upKeyPressedLastFrame) {
            Projetil* novoProj = atirar();  // Or store or add to manager
            // e.g., gerenciadorColisoes->incluirProjetil(novoProj);
        }

        upKeyPressedLastFrame = upNow; // update state for next frame

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

        sprite.setColor(sf::Color::White);  // Reset to normal
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

void Jogador::setTexProjetil(const sf::Texture* tex) {
    texProjetil = tex;
}

Projetil* Jogador::atirar() {
    std::cout << "Atirando" << std::endl;
    sf::Vector2f dir = { 300.f, 0.f };
    return new Projetil(*texProjetil, sprite.getPosition(), dir, Dono::Jogador);
}