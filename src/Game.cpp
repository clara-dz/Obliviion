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

    sf::Texture* player2Texture = new sf::Texture();
    if (!player2Texture->loadFromFile("../assets/images/owlet.png")) {
        std::cerr << "Error loading player texture!" << std::endl;
        exit(1);
    }

    std::string backgroundPath = "../assets/images/background1.png";
    std::string tileTexturePath = "../assets/images/tile1.png";
    
    currentLevel = new JardimDoEden("Garden of Eden",
                                    tileTexturePath,
                                    backgroundPath,
                                    *playerTexture,
                                    *player2Texture,
                                    1000,
                                    playerMode);
    currentLevel->loadLevel();
}

Game::~Game() {
    delete currentLevel;
    delete menu;
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        executar();
        renderizar();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();


        if (gameState == GameState::StartMenu) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    playerMode = PlayerMode::SinglePlayer;
                    gameState = GameState::Playing;
                } else if (event.key.code == sf::Keyboard::Num2) {
                    playerMode = PlayerMode::TwoPlayers;
                    gameState = GameState::Playing;
                }
            }
            return;
        }

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

void Game::processarTelaGameOver() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        telaGameOver.processarEvento(event);
    }

    telaGameOver.atualizar();
    telaGameOver.desenhar(window);

    if (telaGameOver.terminouEntrada()) {
        std::string nome = telaGameOver.getNomeJogador();
        std::cout << "Player name: " << nome << std::endl;
        // TODO: Save score, reset game, or go to main menu

        window.close();  // Temporary action
    }
}

void Game::executar() {
    if (menu->isOpened()) return;
    
    float deltaTime = clock.restart().asSeconds();
    if (deltaTime < 1.f / 144.f)
        deltaTime = 1.f / 144.f;
    
    switch (gameState) {
        case GameState::Playing:
            currentLevel->executar(deltaTime);
            
            if (currentLevel->todosInimigosMortos()) {
                gameState = GameState::NextLevel;
            }else if (currentLevel->jogadoresMortos()) {
                gameState = GameState::GameOver;
            }
            break;

        case GameState::NextLevel:
            // carregarProximoNivel();
            // Here you can load the next level or reset the current one
            std::cout << "Loading next level..." << std::endl;
            // For now, we just reset the current level
            window.close();
            break;

        case GameState::GameOver:
            processarTelaGameOver();
            break;
    }
}

void Game::renderizar() {
    window.clear();

    switch (gameState) {
        case GameState::StartMenu: {
            sf::Text title("Choose Game Mode:\nPress 1 for Single Player\nPress 2 for Two Players", font, 30);
            title.setPosition(100, 200);
            title.setFillColor(sf::Color::White);
            window.draw(title);
            break;
        }

        case GameState::Playing: {
            currentLevel->renderizar(window);
            if (menu->isOpened())
                menu->desenhar(window, sf::RenderStates::Default);
            break;
        }

        case GameState::NextLevel:
            // optionally show a transition screen
            break;

        case GameState::GameOver:
            // Do nothing here, as rendering is handled inside processarTelaGameOver()
            return;  // prevent window.display() from being called again
    }

    window.display();
}
