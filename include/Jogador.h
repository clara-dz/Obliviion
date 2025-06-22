#pragma once
#include "Personagem.h"
#include "Projetil.h"
#include <nlohmann/json.hpp>


using json = nlohmann::json;

class Inimigo;

class Jogador : public Personagem {
    protected:
        int pontos = 0;
        const sf::Texture* texProjetil;
    public:
        Jogador(const sf::Texture& texture);
        
        void die() {
            isAlive = false;
            isVisible = false;
            numVidas = 0; // Ensure numVidas does not go below zero
        }
        
        bool upKeyPressedLastFrame = false;
        void setTexProjetil(const sf::Texture* tex);
        void addPontos(int pts) { pontos += pts; }
        int getPontos() const { return pontos; }
        Projetil* atirar();

        void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
        sf::Vector2f getPosition() const { return sprite.getPosition(); }
        void executar(float deltaTime) override;
        void renderizar(sf::RenderWindow& window) override;
        void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override;
        void reduzirVelocidade(float fator) {
            speed *= fator;
        };

        // void colidir(Inimigo* pIn);
        void setEhJog2(bool flag) { ehJog2 = flag; }
        json salvar();

    private:
        bool ehJog2 = false;
        float speed = 5.f;
};