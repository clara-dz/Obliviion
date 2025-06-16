#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem {
    protected:
        int nivelMaldade;
    public:
        void salvarDataBuffer();
        // virtual void danificar(Jogador* p) = 0;
        Inimigo() : Personagem() {}
        Inimigo(int x, int y, int speed) : Personagem(x, y, speed) {}
        virtual ~Inimigo() = default;
        // virtual void salvar() = 0;
    
        virtual void atacar(Jogador& jogador) = 0;

        // Lógica de ataque do inimigo. Substitui o antigo 'atacar'. Precisa mudar no .cpp
        virtual void executar(float deltaTime) = 0;
        // Função para salvar o estado (será implementada no futuro). Descobrir pq dá erro
        // virtual void salva() = 0;
};