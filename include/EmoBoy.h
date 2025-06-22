#pragma once
#include "Inimigo.h"

class EmoBoy : public Inimigo { //Inimigo Médio
private:
    int tamanho; //professor quer, é preciso utilizar

public:
    EmoBoy(int x, int y, int speed, const sf::Texture& texture);
    void executar(float deltaTime) override;
};
