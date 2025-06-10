#pragma once
#include <SFML/Graphics.hpp>

class Ente {
protected:
    int id;
    static int id_count;

public:
    Ente();
    virtual ~Ente();

    // Replace old pure virtuals with more meaningful names
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
