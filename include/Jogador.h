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
        ~Jogador();
        
        bool upKeyPressedLastFrame = false;
        
        void die();
        void addPontos(int pts);
        void setTexProjetil(const sf::Texture* tex);
        void setPosition(sf::Vector2f pos);
        void executar(float deltaTime) override;
        void renderizar(sf::RenderWindow& window) override;
        void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override;
        void reduzirVelocidade(float fator);
        void setEhJog2(bool flag);
        void setAlive(bool alive);
        void setOnGround(bool onGround);
        void setNumVidas(int vidas);

        int getPontos() const;
        
        Entidades::Projetil* atirar();
        json salvar();

    private:
        bool ehJog2 = false;
        float speed = 5.f;
};