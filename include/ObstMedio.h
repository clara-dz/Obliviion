#pragma once
#include "Obstaculo.h"

namespace Obstaculos {

    class Obst_medio : public Obstaculo {
    private:
        float largura;

    public:
        Obst_medio(const sf::Texture& texture, int x = 0, int y = 0);
        ~Obst_medio();
        
        void update(float deltaTime) override;
        void handleCollision(Entidade& other) override;
        void salva() override;
    };
}