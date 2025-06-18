#include "Personagem.h"

void Personagem::tomarDano(int nivelDano) {
    if (isFlashing) return;

    numVidas -= nivelDano;
    if (numVidas <= 0) {
        isAlive = false;
        numVidas = 0; // Ensure numVidas does not go below zero
    }
    isFlashing = true;
    flashDuration = 0.9f;
    sprite.setColor(sf::Color::Red);
    flashClock.restart();
}
