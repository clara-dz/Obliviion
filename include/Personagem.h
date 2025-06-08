#pragma once
#include "Entidade.h"

class Personagem : public Entidade {
    protected:
        float gravity = 980.f;
        float velocityY = 0.f;
        float velocityX = 0.f;
        float jumpStrength = -300.f;
        bool isOnGround = false;
        int speed;
        float knockbackTimer = 0.f; // in seconds
        bool isAlive;

    public:
        Personagem() : Entidade(), speed(5), isAlive(true) {}
        Personagem(int x, int y, int speed) : Entidade(x, y), speed(speed), isAlive(true) {}
        
        virtual ~Personagem() = default;

        virtual void applyGravity(float deltaTime) {
            if (!isOnGround) {
                velocityY += gravity * deltaTime;
                sprite.move(0.f, velocityY * deltaTime);
            }
        }

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

        virtual void update(float deltaTime) override {
            // Implement character movement logic here (e.g., for the player or enemy)
        }

        virtual void handleCollision(Entidade& other) override {
            // Implement collision logic specific to characters (like taking damage or interacting with platforms)
        }

        virtual sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }

        virtual void move(sf::Vector2f delta) { sprite.move(delta); }

        virtual void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
    
    // Optionally, methods like takeDamage() or attack()
};
