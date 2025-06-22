#pragma once

#include "Inimigo.h"
#include "Projetil.h"
#include <vector>

class EmoBoss : public Inimigo { // Nome: EmoBoss

private:
    short int forca = 2; //dano que o projétil causa no jogador é o dobro do dano q jogador causa em inimigos

public:

    EmoBoss(int x, int y, int speed, const sf::Texture& texture);

    void executar(float deltaTime) override;
};
