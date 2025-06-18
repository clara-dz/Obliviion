#include <iostream>
#include "Personagem.h"

void Personagem::tomarDano(int nivelDano) {
    std::cout << "Vidas restantes: " << nivelDano << std::endl;

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

    std::cout << "Vidas restantes: " << numVidas << std::endl;

}
