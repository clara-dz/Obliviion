#pragma once
#include "Entidade.h"

class Personagem : public Entidade {
    protected:
        float gravity = 0.5f;
        float velocityY = 0.0f;
        bool isOnGround = false;
        int speed;
        bool isAlive;

    public:
        Personagem() : Entidade(), speed(5), isAlive(true) {}
        Personagem(int x, int y, int speed) : Entidade(x, y), speed(speed), isAlive(true) {}
        
        virtual ~Personagem() = default;

        virtual void applyGravity() {
            if (!isOnGround) {
                velocityY += gravity;
                sprite.move(0.f, velocityY);
            }
        }

        void stopFalling() {
            velocityY = 0.f;
            isOnGround = true;
        }

        void startFalling() {
            isOnGround = false;
        }

        float getVelocityY() const { return velocityY; }   
        
        // Override update for character-specific updates (movement, actions, etc.)
        virtual void update() override {
            // Implement character movement logic here (e.g., for the player or enemy)
        }

        virtual void handleCollision(Entidade& other) override {
            // Implement collision logic specific to characters (like taking damage or interacting with platforms)
        }

        // Additional methods specific to characters, such as movement, actions, health, etc.
        void move(int dx, int dy) {
            x += dx * speed;
            y += dy * speed;
        }  
    
    // Optionally, methods like takeDamage() or attack()
};
