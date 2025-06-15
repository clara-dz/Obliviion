#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

namespace Obstaculos {

    class Plataforma : public Obstaculo {
    private:
        int altura; // Atributo específico, pode ser usado para algo no futuro

    public:
        Plataforma(const sf::Texture& texture, int x = 0, int y = 0);
        ~Plataforma();

        // Implementação dos métodos herdados
        void executar(float deltaTime) override;
        void handleCollision(Entidade& other) override;
        void salva() override;
        void obstaculizar(Jogador*p); //ainda n sei para que serve
    };

}