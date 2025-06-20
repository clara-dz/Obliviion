#include "JardimDoEden.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>

JardimDoEden::JardimDoEden(const std::string& name,
                           const std::string& tileTexture,
                           const std::string& bgTextureFile,
                           const sf::Texture& playerTexture,
                           const sf::Texture& player2Texture,
                           int windowWidth,
                           PlayerMode mode)
    : Fase(name), 
      floor(tileTexture, windowWidth, 500), 
      player(playerTexture),
      player2(player2Texture),
      mode(mode)
{
    loadBackgroundTexture(bgTextureFile);

    // Load enemy texture (if needed for future enemies)
    if (!inimigoFracoTexture.loadFromFile("../assets/images/inimigoFraco.png")) {
        std::cerr << "Error loading enemy texture!\n";
    }
    texProjJogador.loadFromFile("../assets/images/rock.png");
    player.setTexProjetil(&texProjJogador);
    player2.setTexProjetil(&texProjJogador);
    player.setPosition(sf::Vector2f(100, 400));
    player2.setPosition(sf::Vector2f(200, 400));
}

void JardimDoEden::loadLevel() {
    if (!plataformaEsqTex.loadFromFile("../assets/images/platLeft.png") ||
        !plataformaMeioTex.loadFromFile("../assets/images/platMid.png") ||
        !plataformaDirTex.loadFromFile("../assets/images/platRight.png")) {
        std::cerr << "Error loading platform textures!\n";
        exit(1);
    }

    // Load platform layout from CSV file
    std::ifstream file("../assets/maps/jardimDoEden.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening level map file!\n";
        exit(1);
    }

    std::string line;
    std::getline(file, line); // Skip the first line (header)

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        float x, y;
        int length;
        char comma;
        ss >> x >> comma >> y >> comma >> length;
        plataformas.emplace_back(plataformaEsqTex, plataformaMeioTex, plataformaDirTex, x, y, length);
    }

    for (int i = 0; i < 3; ++i) {
        InimigoFraco enemy(750 - (70 * i), 200, 20, inimigoFracoTexture);
        weakEnemies.push_back(enemy);
    }

    colisor->resetar();
    colisor->setJogadores(&player, nullptr);
    colisor->incluirInimigos(&weakEnemies[0]); 
}

void JardimDoEden::executar(float deltaTime) {
    player.executar(deltaTime);
    player2.executar(deltaTime);
    colisor->checarColisoes(player, floor, plataformas);
    colisor->checarColisoes(player2, floor, plataformas);
    
    // if (mode == PlayerMode::TwoPlayers) {}

    for (auto& enemy : weakEnemies) {
        colisor->checarColisoes(enemy, floor, plataformas);
        enemy.executar(deltaTime);
        colisor->checarColisaoEntrePersonagens(player, enemy);
        colisor->checarColisaoEntrePersonagens(player2, enemy);
        colisor->tratarColisaoJogsInimigs();
    }
    colisor->atualizarProjeteis(deltaTime);
    colisor->tratarColisaoProjeteis();
    colisor->removerProjeteisInativos();

    if (todosInimigosMortos()) {
        std::cout << "Fase Concluída!\n";
        setCompleted(true);
    }
}

void JardimDoEden::renderizar(sf::RenderWindow& window) {
    drawBackground(window);
    floor.renderizar(window);
    player.renderizar(window);
    player2.renderizar(window);
    player2.setEhJog2(true); // Set player2 as the second player

    // if (mode == PlayerMode::TwoPlayers) {}

    for (auto& enemy : weakEnemies) {
        enemy.renderizar(window);
    }

    for (auto& plataforma : plataformas)
        plataforma.desenhar(window);

    colisor->renderizarProjeteis(window);
}
