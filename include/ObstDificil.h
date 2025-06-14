#pragma once
#include "Obstaculo.h"

namespace Obstaculos {

    class Obst_Dificil : public Obstaculo {
    private:
        short int danosidade; // Quantidade de dano que causa

    public:
        Obst_Dificil(const sf::Texture& texture, int x = 0, int y = 0, short int dano = 10);
        ~Obst_Dificil();
        
        void update(float deltaTime) override;
        void handleCollision(Entidade& other) override;
        void salva() override;
    };
}