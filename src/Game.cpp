#include <iostream>
#include "Game.h"


Game::Game() : window(sf::VideoMode(800, 600), "Obliviion") {
    if (!playerTexture.loadFromFile("../assets/images/player.png")) {
        // Handle loading error
        std::cerr << "Error loading player texture!" << std::endl;
        exit(1); // Exit or handle more gracefully
    }
    player = new Jogador(playerTexture);
}

Game::~Game() {
    // Cleanup code here if needed
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {
    player->update();
}

void Game::render() {
    window.clear();
    player->render(window);
    window.display();
}