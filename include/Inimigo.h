#pragma once
#include "Personagem.h"
#include "Jogador.h"

#pragma once
#include "Personagem.h"

class Inimigo : public Personagem {
    public:
        Inimigo() : Personagem() {}
        Inimigo(int x, int y, int speed) : Personagem(x, y, speed) {}
        virtual ~Inimigo() = default;
    
        virtual void atacar(Jogador& jogador) = 0; // Abstract method to be implemented by subclasses
};