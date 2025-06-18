#include "Personagem.h"

void Personagem::tomarDano(int nivelDano) {
    isFlashing = true;
    flashDuration = 0.9f;
    sprite.setColor(sf::Color::Red);
    flashClock.restart();
}
