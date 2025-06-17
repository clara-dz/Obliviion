#include "JardimDoEden.h"
#include <iostream>
#include <fstream>
#include <sstream>

JardimDoEden::JardimDoEden(const std::string& name,
                           const std::string& tileTexture,
                           const std::string& bgTextureFile,
                           const sf::Texture& playerTexture,
                           int windowWidth)
    : Fase(name), 
      floor(tileTexture, windowWidth, 500), 
      player(playerTexture)
{
    loadBackgroundTexture(bgTextureFile);

    // Load enemy texture (if needed for future enemies)
    if (!inimigoFracoTexture.loadFromFile("../assets/images/inimigoFraco.png")) {
        std::cerr << "Error loading enemy texture!\n";
    }
}

void JardimDoEden::loadLevel() {
    // Load textures
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

    for (int i = 0; i < 1; ++i) {
        InimigoFraco enemy(600, 200, 400, inimigoFracoTexture);
        weakEnemies.push_back(enemy);
    }
}

void JardimDoEden::executar(float deltaTime) {
    player.executar(deltaTime);
    colisor.checarColisoes(player, floor, plataformas);

    for (auto& enemy : weakEnemies) {
        colisor.checarColisoes(enemy, floor, plataformas);
        enemy.executar(deltaTime);
        colisor.checarColisaoEntrePersonagens(player, enemy);
    }
}

void JardimDoEden::renderizar(sf::RenderWindow& window) {
    drawBackground(window);
    floor.renderizar(window);
    player.renderizar(window);

    for (auto& enemy : weakEnemies) {
        enemy.renderizar(window);
    }

    for (auto& plataforma : plataformas)
        plataforma.desenhar(window);

}
