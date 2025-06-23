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
        
        void die();
        
        bool upKeyPressedLastFrame = false;

        void addPontos(int pts);

        int getPontos() const;
        
        Entidades::Projetil* atirar();

        void setTexProjetil(const sf::Texture* tex);

        void setPosition(sf::Vector2f pos);
       
        void executar(float deltaTime) override;

        void renderizar(sf::RenderWindow& window) override;

        void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override;

        void reduzirVelocidade(float fator);

        void setEhJog2(bool flag) { ehJog2 = flag; }

        json salvar();

        void setAlive(bool alive) { isAlive = alive; }

        void setOnGround(bool onGround) { isOnGround = onGround; }
        
        void setNumVidas(int vidas) { numVidas = vidas; }

    private:
        bool ehJog2 = false;
        float speed = 5.f;
};