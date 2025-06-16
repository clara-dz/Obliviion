#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"

class Ente {
protected:
    int id;
    static int id_count;
    static GerenciadorGrafico* pGG;

public:
    Ente();
    virtual ~Ente();

    // Replace old pure virtuals with more meaningful names
    virtual void executar(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
