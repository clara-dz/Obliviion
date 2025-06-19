#pragma once
#include "Personagem.h"
#include "Projetil.h"
// #include "Inimigo.h"

class Inimigo;

class Jogador : public Personagem {
    protected:
        int pontos;
        const sf::Texture* texProjetil;
    public:
        Jogador(const sf::Texture& texture);

        bool upKeyPressedLastFrame = false;
        void setTexProjetil(const sf::Texture* tex);
        Projetil* atirar();

        void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
        void executar(float deltaTime) override;
        void renderizar(sf::RenderWindow& window) override;
        void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override;

        void colidir(Inimigo* pIn);
        // void salvar() override;
    private:
        float speed = 5.f;
};