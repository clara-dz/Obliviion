#pragma once

#include "Personagem.h"

class Jogador : public Personagem, public sf::Drawable {
    public:
        Jogador();
        void move() override;
        void render(sf::RenderWindow& window) override;

    private:
        float speed = 5.f;
    

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};