#pragma once

#include "Inimigo.h"

class EmoGirl : public Inimigo { // Inimigo Fraco
private:
    float raio = 60.f;
    float traveled = 0.f;
    bool movingLeft;

public:
    EmoGirl(int x, int y, int speed, const sf::Texture& texture, bool movingLeft = true);
    void executar(float deltaTime) override;
    

    // void renderizar(sf::RenderWindow& window) override {
    //     window.draw(sprite);
    // }

    // void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override {
    //     target.draw(sprite, states);
    // }
};
