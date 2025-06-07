#pragma once
#include "Personagem.h"


class Jogador : public Personagem {
    public:
        Jogador(const sf::Texture& texture);
        sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }
        void move(sf::Vector2f delta) { sprite.move(delta); }
        void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
        void update(float deltaTime) override;
        void render(sf::RenderWindow& window) override;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        float speed = 0150.f;
};