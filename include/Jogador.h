#pragma once
#include "Personagem.h"
// #include "Inimigo.h"

class Inimigo;

class Jogador : public Personagem {
    protected:
        int pontos;

    public:
        Jogador(const sf::Texture& texture);
        void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
        void executar(float deltaTime) override;
        // void salvar() override;
        void renderizar(sf::RenderWindow& window) override;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void colidir(Inimigo* pIn);

    private:
        float speed = 5.f;
};