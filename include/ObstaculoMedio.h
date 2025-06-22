#pragma once
#include "Obstaculo.h"

//namespace Obstaculos {

    class Obst_Medio : public Obstaculo {
    private:
        float largura;

    public:
        Obst_Medio(const sf::Texture& texture, int x = 0, int y = 0);
        ~Obst_Medio();
        
        void executar(float deltaTime) override;
    };
//}