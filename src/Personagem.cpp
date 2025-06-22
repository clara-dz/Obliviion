#include <iostream>
#include "Personagem.h"
#include <nlohmann/json.hpp>


using json = nlohmann::json;

void Personagem::tomarDano(int nivelDano) {
    std::cout << "Damage: " << nivelDano << "|" << numVidas << std::endl;

    if (isFlashing) return;

    numVidas -= nivelDano;
    if (numVidas <= 0) {
        std::cout << "dead" << std::endl;
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
