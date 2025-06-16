#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"

class Ente {
    protected:
        int id;
        static int id_count;
        static Gerenciadores::GerenciadorGrafico* pGG;

    public:
        Ente();
        virtual ~Ente();

        // Replace old pure virtuals with more meaningful names
        virtual void executar(float deltaTime) = 0;
        virtual void renderizar(sf::RenderWindow& window) = 0;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

        void setGG(Gerenciadores::GerenciadorGrafico* pG);
};
