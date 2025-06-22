#pragma once
#include "Obstaculo.h"

//namespace Obstaculos {

    class BarreiraDoLimbo : public Obstaculo {
    private:
        float largura;

    public:
        BarreiraDoLimbo(const sf::Texture& texture, int x = 0, int y = 0);
        ~BarreiraDoLimbo();
        
        void executar(float deltaTime) override;
        void salva() override;
    };
//}