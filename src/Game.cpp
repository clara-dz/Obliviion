#include <iostream>
#include "Game.h"


Game::Game() : window(sf::VideoMode(800, 600), "Obliviion") {
    if (!font.loadFromFile("../assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font.\n";
        exit(1);
    }

    std::vector<std::string> options = {"Resume", "Option", "Sair"};
    menu = new Menu(options, font);

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
    delete menu;
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
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            if (menu->isOpened())
                menu->close();
            else
                menu->open();
        }

        if (menu->isOpened()) {
            menu->handleEvent(event, window);
        }
    }
}

void Game::update() {
    if (!menu->isOpened()) {
        float deltaTime = clock.restart().asSeconds();
        if (deltaTime < 1.f / 144.f)
            deltaTime = 1.f / 144.f;
        currentLevel->update(deltaTime);
    }
}

void Game::render() {
    window.clear();
    currentLevel->render(window);
    if (menu->isOpened()) {
        menu->draw(window);
    }
    window.display();
}