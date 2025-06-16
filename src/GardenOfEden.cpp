#include "GardenOfEden.h"
#include <iostream>

GardenOfEden::GardenOfEden(const std::string& name,
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

void GardenOfEden::loadLevel() {
    for (int i = 0; i < 1; ++i) {
        InimigoFraco enemy(600, 200, 400, inimigoFracoTexture);
        weakEnemies.push_back(enemy);
    }
}

void GardenOfEden::executar(float deltaTime) {
    player.executar(deltaTime);
    colisor.checarColisoes(player, floor);

    for (auto& enemy : weakEnemies) {
        colisor.checarColisoes(enemy, floor);
        enemy.executar(deltaTime);
        colisor.checarColisaoEntrePersonagens(player, enemy);
    }
}

void GardenOfEden::renderizar(sf::RenderWindow& window) {
    drawBackground(window);
    floor.renderizar(window);
    player.renderizar(window);

    for (auto& enemy : weakEnemies) {
        enemy.renderizar(window);
    }
}
