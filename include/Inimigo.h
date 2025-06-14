#pragma once
#include "Personagem.h"

// Forward-declare para evitar dependência circular
class Jogador; 

class Inimigo : public Personagem {
protected:
    int nivel_maldade;

public:
    Inimigo() : Personagem(), nivel_maldade(0) {}
    Inimigo(int x, int y, int speed) : Personagem(x, y, speed), nivel_maldade(0) {}
    virtual ~Inimigo() = default;
    
    // Lógica de ataque do inimigo. Substitui o antigo 'atacar'.
    virtual void danificar(Jogador* pJogador) = 0; 
    
    // Função para salvar o estado (será implementada no futuro)
    virtual void salva() = 0;
};