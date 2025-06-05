#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Obliviion") {
    player.setSize(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(375.f, 275.f); // roughly centered
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

    // Simple movement logic (non-frame-rate independent)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.move(-5.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.move(5.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.move(0.f, -5.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.move(0.f, 5.f);

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void  Game::update() {
    //TODO: implement
}

void Game::render() {
    window.clear();
    // Draw your game objects here
    window.draw(player);
    window.display();
}