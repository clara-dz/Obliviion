#include "Personagem.h"

void Personagem::takeDamage() {
    isFlashing = true;
    flashDuration = 0.9f;
    sprite.setColor(sf::Color::Red);
    flashClock.restart();
}
