#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"

class Ente {
    protected:
        int id;                      //id das instâncias
        static int id_contador;     //id da classe
        static Gerenciadores::GerenciadorGrafico* pG;
        sf::Sprite* sprite;

    public:
        Ente();
        virtual ~Ente();

        void setGG(Gerenciadores::GerenciadorGrafico* pGG);

        // Funções a serem usadas por suas classes filhas
        virtual void executar(float deltaTime) = 0;
        virtual void renderizar(sf::RenderWindow& window) = 0;
        virtual void desenhar(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
