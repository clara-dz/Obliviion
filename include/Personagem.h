#pragma once
#include "Entidade.h"
#include <nlohmann/json.hpp>


using json = nlohmann::json;

class Personagem : public Entidade {
    protected:
        int numVidas;

        float gravityUp = 2.f;
        float gravityDown = 5.f;
        float velocityY = 0.f;
        float velocityX = 0.f;
        float jumpStrength = -30.f;
        int speed;
        
        bool isFlashing = false;
        bool isOnGround = false;
        
        float knockbackTimer = 0.f; // in seconds
        float flashDuration = 0.0f;
        sf::Clock flashClock;

    public:
        bool isAlive;

        Personagem();
        Personagem(int x, int y, int speed, int vidas = 1);
        
        virtual ~Personagem();

        virtual void applyGravity(float deltaTime);

        void stopFalling();

        void startFalling();

        void setVelocityX(float vx);

        float getVelocityX() const;

        void setVelocityY(float vy);

        float getVelocityY() const;  
        
        void setKnockbackTimer(float t);

        bool isFlashingNow() const;

        bool estaVivo() const;

        virtual void executar(float deltaTime) override;

        virtual sf::FloatRect getBounds() const;

        virtual void move(sf::Vector2f delta);

        virtual void setPosition(sf::Vector2f pos);

        virtual void tomarDano(int nivelDano = 1);

        virtual void setVida(int vida);

        virtual sf::Vector2f getPosition() const { return sprite.getPosition(); }

        virtual int getNumVidas() const { return numVidas; }
};
