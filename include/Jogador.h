#pragma once
#include "Personagem.h"


class Jogador : public Personagem {
    public:
        Jogador(const sf::Texture& texture);
        void update() override;
        void render(sf::RenderWindow& window) override;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        float speed = 5.f;
};