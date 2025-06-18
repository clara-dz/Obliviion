#pragma once
#include "Entidade.h"

class Personagem : public Entidade {
    protected:
        int numVidas;
        float gravityUp = 2.f;
        float gravityDown = 5.f;
        float velocityY = 0.f;
        float velocityX = 0.f;
        float jumpStrength = -30.f;
        bool isOnGround = false;
        float knockbackTimer = 0.f; // in seconds
        int speed;
        bool isAlive;
        bool isFlashing = false;
        float flashDuration = 0.0f;
        sf::Clock flashClock;

    public:
        Personagem() : Entidade(), speed(5), isAlive(true) {}
        Personagem(int x, int y, int speed) : Entidade(x, y), speed(speed), isAlive(true) {}
        
        virtual ~Personagem() = default;

        virtual void applyGravity(float deltaTime) {
            if (!isOnGround) {
                float currentGravity = (velocityY < 0.f) ? gravityUp : gravityDown;
                velocityY += currentGravity * deltaTime;
                sprite.move(0.f, velocityY * deltaTime);
            }
        }
        void salvarDataBuffer();

        // virtual void salvar() = 0;

        void stopFalling() {
            velocityY = 0.f;
            isOnGround = true;
        }

        void startFalling() {
            isOnGround = false;
        }

        void setVelocityX(float vx) { velocityX = vx; }

        float getVelocityX() const { return velocityX; }

        void setVelocityY(float vy) { velocityY = vy; }

        float getVelocityY() const { return velocityY; }   
        
        void setKnockbackTimer(float t) { knockbackTimer = t; }

        bool isFlashingNow() const { return isFlashing; }

        virtual void executar(float deltaTime) override {
            // Implement character movement logic here (e.g., for the player or enemy)
        }

        virtual void handleCollision(Entidade& other) override {
            // Implement collision logic specific to characters (like taking damage or interacting with platforms)
        }

        virtual sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }

        virtual void move(sf::Vector2f delta) { sprite.move(delta); }

        virtual void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }

        virtual void tomarDano(int nivelDano);
};
