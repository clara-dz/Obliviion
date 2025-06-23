#include "Jogador.h"
#include "Projetil.h"
#include "GerenciadorColisoes.h"
#include <iostream>


Jogador::Jogador(const sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(375.f, 275.f);
    numVidas = 20;
    isAlive = true;
    isVisible = true;
}
Jogador::~Jogador() {}

void Jogador::die() {
    isAlive = false;
    isVisible = false;
    numVidas = 0; // Ensure numVidas does not go below zero
}

void Jogador::addPontos(int pts) { pontos += pts; }

int Jogador::getPontos() const { return pontos; }

void Jogador::executar(float deltaTime) {
    if (!isAlive) return; // If the player is not alive, skip execution
    if (knockbackTimer > 0.f) {
        knockbackTimer -= deltaTime;
    } else {
        knockbackTimer = 0.f; // Reset timer

        if (!ehJog2) {   
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                velocityX = -speed;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                velocityX = speed;
            bool upNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

            if (upNow && !upKeyPressedLastFrame) {
                Projetil* novoProj = atirar();
                GerenciadorColisoes::getInstancia()->incluirProjetil(novoProj);
            }

            upKeyPressedLastFrame = upNow; // update state for next frame

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isOnGround) {
                std::cout << "Jumping1" << std::endl;

                velocityY = jumpStrength;
                isOnGround = false;
            }
        } else { // Jogador 2 controls
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                velocityX = -speed;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                velocityX = speed;
            bool upNow = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);

            if (upNow && !upKeyPressedLastFrame) {
                Projetil* novoProj = atirar();
                GerenciadorColisoes::getInstancia()->incluirProjetil(novoProj);
            }

            upKeyPressedLastFrame = upNow; // update state for next frame

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isOnGround) {
                std::cout << "Jumping2" << std::endl;

                velocityY = jumpStrength;
                isOnGround = false;
            }
        }
    }
    sprite.move(velocityX * deltaTime, 0.f);
    velocityX *= 0.9f;
    if (std::abs(velocityX) < 1.f) velocityX = 0.f;
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

void Jogador::setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }

Projetil* Jogador::atirar() {
    std::cout << "Pontos " << ehJog2 << " : " << getPontos() << "\n";

    sf::Vector2f vel = { 10.f, 0.f };
    return new Projetil(*texProjetil, sprite.getPosition(), vel, Dono::Jogador);
}
void Jogador::reduzirVelocidade(float fator) {
    speed *= fator;
};

json Jogador::salvar() {
    json data;
    data["isAlive"] = isAlive;
    data["numVidas"] = numVidas;
    data["x"] = sprite.getPosition().x;
    data["y"] = sprite.getPosition().y;

    data["velocityX"] = velocityX;
    data["velocityY"] = velocityY;
    data["isOnGround"] = isOnGround;

    return data;
}