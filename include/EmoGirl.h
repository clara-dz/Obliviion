#pragma once

#include "Inimigo.h"

class EmoGirl : public Inimigo { //Nome: EmoGirl
private:
    float raio;  // é preciso usar 

public:
    EmoGirl(int x, int y, int speed, const sf::Texture& texture);

    void executar(float deltaTime) override;
};
