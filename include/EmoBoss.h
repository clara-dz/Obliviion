#pragma once

#include "Inimigo.h"
#include "Projetil.h"
#include <vector>

class EmoBoss : public Inimigo { // Nome: EmoBoss
protected:
    const sf::Texture* texProjetil;

private:
    short int forca = 2; //dano que o projétil causa no jogador é o dobro do dano q jogador causa em inimigos
    Jogador* pJog1;
    Jogador* pJog2;

    sf::Clock shootClock;
    const float shootCooldown = 1.5f; // Tempo entre tiros em segundos

public:
    EmoBoss(int x, int y, int speed, const sf::Texture& texture);

    void executar(float deltaTime) override;
    void attackPlayer(float deltaTime, Jogador* pJogador);
    void setJogadores(Jogador* j1, Jogador* j2);
    
    Projetil* atirar();
    void setTexProjetil(const sf::Texture* tex);
};
