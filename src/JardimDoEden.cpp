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
    player2.setEhJog2(true); // Set player2 as the second player
}

void JardimDoEden::loadLevel() {
    if (!plataformaEsqTex.loadFromFile("../assets/images/platLeft.png") ||
        !plataformaMeioTex.loadFromFile("../assets/images/platMid.png") ||
        !plataformaDirTex.loadFromFile("../assets/images/platRight.png")) {
        std::cerr << "Error loading platform textures!\n";
        exit(1);
    }

    if (!smokeTex.loadFromFile("../assets/images/smoke.gif") ||
        !fireTex.loadFromFile("../assets/images/fire.gif")) {
        std::cerr << "Error loading platform textures!\n";
        exit(1);
    }

    obstaculos.push_back(new Smoke(smokeTex, 400, 356));

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

    for (auto& o : obstaculos) {
        colisor->incluirObstaculo(o);
    }

    for (int i = 0; i < 3; ++i) {
        InimigoFraco enemy(750 - (70 * i), 200, 20, inimigoFracoTexture);
        weakEnemies.push_back(enemy);
    }

    // colisor->resetar();
    colisor->setJogadores(&player, &player2);
    for (auto& inimigo : weakEnemies) {
        colisor->incluirInimigos(&inimigo);
    }
    for (auto& inimigo : mediumEnemies) {
        colisor->incluirInimigos(&inimigo);
    }
}

void JardimDoEden::executar(float deltaTime) {
    player.executar(deltaTime);
    player2.executar(deltaTime);
    if (player.isAlive)
        colisor->checarColisoes(player, floor, plataformas);

    if (player2.isAlive)
        colisor->checarColisoes(player2, floor, plataformas);
    
    std::cout << "[DEBUG] Obstáculos ativos: " << colisor->getListaObstaculosSize() << std::endl;

    // if (mode == PlayerMode::TwoPlayers) {}

    for (auto& enemy : weakEnemies) {
        if (!enemy.isAlive) continue; // Skip dead enemies
        
        enemy.executar(deltaTime);
        colisor->checarColisoes(enemy, floor, plataformas);
        
        if (player.isAlive) {
            colisor->checarColisaoEntrePersonagens(player, enemy);
            colisor->tratarColisaoJogsInimigs(player, enemy);
        }
        if (player2.isAlive) {
            colisor->checarColisaoEntrePersonagens(player2, enemy);
            colisor->tratarColisaoJogsInimigs(player2, enemy);
        }
    }
    colisor->atualizarProjeteis(deltaTime);
    colisor->tratarColisaoProjeteis();
    colisor->removerProjeteisInativos();
    colisor->tratarColisaoJogsObstacs();


    if (todosInimigosMortos()) {
        std::cout << "Fase Concluída!\n";
        setCompleted(true);
    }
}

void JardimDoEden::renderizar(sf::RenderWindow& window) {
    drawBackground(window);
    floor.renderizar(window);
    for (auto* obst : obstaculos) {
        if (obst) {
            obst->renderizar(window);
        }
    }

    if (player.isAlive)
        player.renderizar(window);
    
    if (player2.isAlive)
        player2.renderizar(window);

    // if (mode == PlayerMode::TwoPlayers) {}

    for (auto& enemy : weakEnemies) {
        if (enemy.isAlive) // Only render alive enemies
        enemy.renderizar(window);
    }

    for (auto& plataforma : plataformas)
        plataforma.desenhar(window);

    colisor->renderizarProjeteis(window);
}
