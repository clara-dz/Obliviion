#pragma once
#include "Inimigo.h"
#include "Jogador.h"


class EmoBoy : public Inimigo { //Inimigo Médio
private:
    int tamanho = 2;
    Jogador* pJog1;
    Jogador* pJog2;

    float detectionRadius = 15.f;
    float lateralWiggleTimer = 0.f;
    float lateralWiggleDuration = 1.f;
    float lateralWiggleDirection = 0.f;

public:
    EmoBoy(int x, int y, int speed, const sf::Texture& texture);
    void executar(float deltaTime) override;
    void setJogadores(Jogador* j1, Jogador* j2);
    void attackPlayer(float deltaTime, Jogador* pJogador);
};
