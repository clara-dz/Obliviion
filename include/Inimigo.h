#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem {
    protected:
        int nivel_maldade;
        int hp; //hit points

    public:
        Inimigo();
        virtual ~Inimigo();
        
        void salvarDataBuffer();
        virtual void executar() = 0;
        virtual void danificar(Jogador* p) = 0;
        virtual void salvar() = 0;
};