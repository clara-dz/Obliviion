#include "Jogador.h"


Jogador::Jogador() {
    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(375.f, 275.f);
}

void Jogador::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        shape.move(-speed, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        shape.move(speed, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        shape.move(0.f, -speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        shape.move(0.f, speed);
}

void Jogador::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void Jogador::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);  // Actual drawing of the shape
}