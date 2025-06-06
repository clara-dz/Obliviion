#include "Game.h"


Game::Game() : window(sf::VideoMode(800, 600), "Obliviion") {}

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

void  Game::update() {
    player.move();
}

void Game::render() {
    window.clear();
    // Draw your game objects here
    window.draw(player);
    window.display();
}