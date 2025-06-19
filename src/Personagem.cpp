#include <iostream>
#include "Personagem.h"

void Personagem::tomarDano(int nivelDano) {
    std::cout << "Damage: " << nivelDano << std::endl;

    if (isFlashing) return;

    numVidas -= nivelDano;
    if (numVidas <= 0) {
        isAlive = false;
        numVidas = 0; // Ensure numVidas does not go below zero
        isVisible = false;
    }
    isFlashing = true;
    flashDuration = 0.2f;
    sprite.setColor(sf::Color::Red);
    flashClock.restart();

    std::cout << "remaining life: " << numVidas << std::endl;

}
