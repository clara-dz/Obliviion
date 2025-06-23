#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>
#include "Game.h"
#include "Jogador.h"
#include "InfernoDeDante.h"
#include "Config.h"

extern const unsigned int SCREEN_WIDTH;
extern const unsigned int SCREEN_HEIGHT;
using json = nlohmann::json;


std::vector<std::pair<std::string, int>> lerPontuacoes() {
    std::ifstream arquivo("../assets/ranking.csv");
    std::vector<std::pair<std::string, int>> pontuacoes;
    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string nome;
        int pontos;
        if (std::getline(ss, nome, ',') && ss >> pontos) {
            pontuacoes.emplace_back(nome, pontos);
        }
    }

    // Optional: sort descending
    std::sort(pontuacoes.begin(), pontuacoes.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    return pontuacoes;
}

Game::Game() : window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Obliviion") {
    if (!font.loadFromFile("../assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font.\n";
        exit(1);
    }

    std::vector<std::string> options = {
        "Continuar",
        "Sair",
        "Score",
        "Salvar",
        "Carregar",
        "Jardim do Eden",
        "Inferno de Dante"
    };
    menu = new Menu(options, font);

    if (!playerTexture.loadFromFile("../assets/images/player.png")) {
        std::cerr << "Error loading player texture!" << std::endl;
        exit(1);
    }

    if (!player2Texture.loadFromFile("../assets/images/owlet.png")) {
        std::cerr << "Error loading player texture!" << std::endl;
        exit(1);
    }

    pJog1 = new Jogador(playerTexture);
    pJog2 = new Jogador(player2Texture);

    texProjJogador.loadFromFile("../assets/images/rock.png");
    pJog1->setTexProjetil(&texProjJogador);
    pJog2->setTexProjetil(&texProjJogador);
    pJog1->setPosition(sf::Vector2f(50, 400));
    pJog2->setPosition(sf::Vector2f(200, 400));
    pJog2->setEhJog2(true); // Set player2 as the second player
}

void Game::iniciarFase(std::string NomeFase) {
    currentLevelName = NomeFase;

    if (playerMode == PlayerMode::SinglePlayer) {
        std::cout << "Why are you playing alone? :(" << std::endl;
        pJog2->die();
    }

    if (currentLevelName == "Jardim do Éden") {
        std::cout << "Loading Jardim do Éden level..." << std::endl;
        currentLevel = new JardimDoEden(pJog1, pJog2);
    } else if (currentLevelName == "Inferno de Dante") {
        std::cout << "Loading Inferno de Dante level..." << std::endl;
        currentLevel = new InfernoDeDante(pJog1, pJog2);
    } else {
        std::cerr << "Unknown level: " << currentLevelName << std::endl;
        return;
    }

    currentLevel->loadLevel();
    gameState = GameState::Playing;
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
    if (gameState == GameState::GameOver)
        return;
    
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (gameState == GameState::StartMenu) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    std::cout << "Single Player Mode Selected" << std::endl;
                    playerMode = PlayerMode::SinglePlayer;
                    iniciarFase("Jardim do Éden");
                } else if (event.key.code == sf::Keyboard::Num2) {
                    std::cout << "Two Players Mode Selected" << std::endl;
                    playerMode = PlayerMode::TwoPlayers;
                    iniciarFase("Jardim do Éden");
                }
            }
            return;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            if (gameState == GameState::Ranking) {
                std::cout << "Returning to game..." << std::endl;
                gameState = GameState::Playing;  
            } else {
                if (menu->isOpened())
                    menu->close();
                else
                    menu->open();
            }
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
        
        // Safeguard: fallback name
        if (nome.empty()) nome = "Anonimo";

        // Get score from currentLevel
        int pontos = currentLevel->getPontuacaoTotalJogadores();  // <-- implement this

        salvarPontuacao(nome, pontos);
        std::cout << "Pontuação salva: " << nome << ", " << pontos << " pontos." << std::endl;

        window.close();  // or reset game
    }
}

void Game::executar() {
    if (menu->isOpened()) {
        return;
    }
    
    std::string selected = menu->getSelectedOption();
    menu->resetSelection();

    if (selected == "Salvar") {
        salvarJogo();
        std::cout << "Game saved successfully." << std::endl;
    }

    if (selected == "Carregar") {
        carregarJogo();
    }

    if (selected == "Score" && gameState == GameState::Playing) {
        std::cout << "Opening ranking screen..." << std::endl;
        gameState = GameState::Ranking;
        return;
    };

    if (selected == "Jardim do Eden") {
        currentLevel->reset();
        iniciarFase("Jardim do Éden");
        return;
    }
    
    if (selected == "Inferno de Dante") {
        currentLevel->reset();
        iniciarFase("Inferno de Dante");
        return;
    }
    
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
            trocarFase();
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
        
        case GameState::Ranking: {
            sf::Text titulo("Score", font, 36);
            titulo.setPosition(300, 50);
            titulo.setFillColor(sf::Color::White);
            window.draw(titulo);

            auto scores = lerPontuacoes();
            int y = 120;
            int count = 0;
            for (const auto& [nome, pontos] : scores) {
                if (++count > 5) break;  // only show top 5
                sf::Text linha(nome + ": " + std::to_string(pontos), font, 28);
                linha.setPosition(280, y);
                linha.setFillColor(sf::Color::Cyan);
                window.draw(linha);
                y += 40;
            }

            sf::Text hint("Pressione ESC para voltar", font, 20);
            hint.setPosition(250, y + 20);
            hint.setFillColor(sf::Color(150, 150, 150));
            window.draw(hint);
            break;
        }
    }

    window.display();
}


void Game::salvarPontuacao(const std::string& nome, int pontos) {
    std::ofstream arquivo("../assets/ranking.csv", std::ios::app); // append mode
    if (arquivo.is_open()) {
        arquivo << nome << "," << pontos << "\n";
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de ranking!" << std::endl;
    }
}

void Game::salvarJogo() {
    json saveData;

    saveData = currentLevel->salvar();
    saveData["playerMode"] = playerMode;
    saveData["token"] = "ObliviionSaveData";

    salvarDataBuffer(saveData);
}

void Game::salvarDataBuffer(json saveData) {
    std::cout << "Salvando dados do buffer no arquivo." << std::endl;

    std::ofstream out("../assets/savegame.json");
    if (out.is_open()) {
        out << saveData.dump(4);
        out.close();
        std::cout << "Jogo salvo com sucesso.\n";
    } else {
        std::cerr << "Erro ao salvar jogo.\n";
    }
}


void Game::carregarJogo() {
    std::cout << "Carregando jogo..." << std::endl;

    std::ifstream in("../assets/savegame.json");
    if (!in.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de salvamento." << std::endl;
        return;
    }

    json saveData;
    in >> saveData;

    if (saveData["token"] != "ObliviionSaveData") {
        std::cerr << "Arquivo de salvamento inválido." << std::endl;
        return;
    }

    playerMode = saveData["playerMode"];

    for (auto& enemy : saveData["mediumEnemies"]) {
        std::cout << enemy.dump(4) << std::endl;
    }
    for (auto& enemy : saveData["mediumEnemies"]) {
        std::cout << enemy.dump(4) << std::endl;
    }
        for (auto& enemy : saveData["mediumEnemies"]) {
        std::cout << enemy.dump(4) << std::endl;
    }

    if (saveData["levelName"] == "Jardim do Eden") {
        currentLevel->reset();
        iniciarFase("Jardim do Éden");
    } else if (saveData["levelName"] == "Inferno de Dante") {
        currentLevel->reset();
        iniciarFase("Inferno de Dante");
    } else {
        std::cerr << "Fase desconhecida: " << saveData["levelName"] << std::endl;
        return;
    }

    currentLevel->reset();
    carregarJogadores(saveData);
    currentLevel->carregar(saveData);
}

void Game::carregarJogadores(json saveData) {

    if (saveData.contains("player1")) {
        auto& player1Data = saveData["player1"];
        pJog1->setAlive(player1Data["isAlive"]);
        pJog1->setOnGround(player1Data["isOnGround"]);
        pJog1->setNumVidas(player1Data["numVidas"]);
        pJog1->setVelocityX(player1Data["velocityX"]);
        pJog1->setVelocityY(player1Data["velocityY"]);
        pJog1->setPosition(sf::Vector2f(player1Data["x"], player1Data["y"]));
    }

    if (saveData.contains("player2")) {
        auto& player2Data = saveData["player2"];
        pJog2->setAlive(player2Data["isAlive"]);
        pJog2->setOnGround(player2Data["isOnGround"]);
        pJog2->setNumVidas(player2Data["numVidas"]);
        pJog2->setVelocityX(player2Data["velocityX"]);
        pJog2->setVelocityY(player2Data["velocityY"]);
        pJog2->setPosition(sf::Vector2f(player2Data["x"], player2Data["y"]));
    }
}

void Game::trocarFase() {
    std::cout << "Trocando de fase...\n";

    // Clean up safely
    if (currentLevel) {
        delete currentLevel;
        currentLevel = nullptr;
    }

    // Start next level
    if (currentLevelName == "Jardim do Éden") {
        iniciarFase("Inferno de Dante");
    } else {
        std::cout << "Fim do jogo! Não há mais fases." << std::endl;
        gameState = GameState::Victory;
    }
}
