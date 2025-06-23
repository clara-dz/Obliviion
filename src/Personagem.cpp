#include <iostream>
#include "Personagem.h"
#include <nlohmann/json.hpp>


using json = nlohmann::json;

        Personagem::Personagem () : Entidade(), speed(5), isAlive(true), numVidas(1) {}

        Personagem::Personagem (int x, int y, int speed, int vidas)
            : Entidade(x, y), speed(speed), isAlive(true), numVidas(vidas) {}
        
        Personagem::~Personagem() {}

        void Personagem::applyGravity(float deltaTime) {    //implementação com ajuda do ChatGPT
            if (!isOnGround) {
                float currentGravity = (velocityY < 0.f) ? gravityUp : gravityDown;
                velocityY += currentGravity * deltaTime;
                sprite.move(0.f, velocityY * deltaTime);
            }
        }

        void Personagem::stopFalling() {
            velocityY = 0.f;
            isOnGround = true;
        }

        void Personagem::startFalling() {
            isOnGround = false;
        }

        void Personagem::setVelocityX(float vx) { velocityX = vx; }

        float Personagem::getVelocityX() const { return velocityX; }

        void Personagem::setVelocityY(float vy) { velocityY = vy; }

        float Personagem::getVelocityY() const { return velocityY; }   
        
        void Personagem::setKnockbackTimer(float t) { knockbackTimer = t; }

        bool Personagem::isFlashingNow() const { return isFlashing; }

        bool Personagem::estaVivo() const { return isAlive; }

        void Personagem::executar(float deltaTime) {
            // Implement character movement logic here (e.g., for the player or enemy)
        }
        
        sf::FloatRect Personagem::getBounds() const {
            return sprite.getGlobalBounds();
        }

        void Personagem::move(sf::Vector2f delta) { sprite.move(delta); }

        void Personagem::setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }

        void Personagem::setVida(int vida) {numVidas = vida;}

        void Personagem::tomarDano(int nivelDano) {
            std::cout << "Damage: " << nivelDano << "|" << numVidas << std::endl;

             if (isFlashing) return;

            numVidas -= nivelDano;
            if (numVidas <= 0) {
            std::cout << "dead" << std::endl;
            isAlive = false;
            numVidas = 0; // Ensure numVidas does not go below zero
            isVisible = false;
     }
            isFlashing = true;
            flashDuration = 0.2f;
            sprite.setColor(sf::Color::Red);
            flashClock.restart();

            std::cout << "remaining life: " << numVidas << std::endl;
}
        sf::Vector2f Personagem::getPosition() const { return sprite.getPosition(); }
