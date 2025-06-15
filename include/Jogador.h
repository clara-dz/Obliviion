#pragma once
#include "Personagem.h"


class Jogador : public Personagem {
    public:
        Jogador(const sf::Texture& texture);
        void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
        void executar(float deltaTime) override;
        void render(sf::RenderWindow& window) override;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        float speed = 5.f;
};