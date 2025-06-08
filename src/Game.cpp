#include <iostream>
#include "Game.h"


Game::Game() : window(sf::VideoMode(800, 600), "Obliviion") {
    sf::Texture* playerTexture = new sf::Texture();
    if (!playerTexture->loadFromFile("../assets/images/player.png")) {
        std::cerr << "Error loading player texture!" << std::endl;
        exit(1);
    }

    std::string backgroundPath = "../assets/images/background1.png";
    std::string tileTexturePath = "../assets/images/tile1.png";
    
    currentLevel = new GardenOfEden("Garden of Eden",
                                    tileTexturePath,
                                    backgroundPath,
                                    *playerTexture,
                                    1000);
    currentLevel->loadLevel();
}

Game::~Game() {
    delete currentLevel;
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
    float deltaTime = clock.restart().asSeconds();
    if (deltaTime < 0.0001f)
        deltaTime = 0.0001f;
    currentLevel->update(deltaTime);
}

void Game::render() {
    window.clear();
    currentLevel->render(window);
    window.display();
}