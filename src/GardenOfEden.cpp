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
    // Example: load 5 enemies in specific positions
    for (int i = 0; i < 1; ++i) {
        InimigoFraco enemy(100, 150, 400, inimigoFracoTexture);
        weakEnemies.push_back(enemy);
    }
}

void GardenOfEden::update(float deltaTime) {
    player.update(deltaTime);
    colisor.checarColisoes(player, floor);

    for (auto& enemy : weakEnemies) {
        enemy.update(deltaTime);
        colisor.checarColisoes(enemy, floor);
    }
}

void GardenOfEden::render(sf::RenderWindow& window) {
    drawBackground(window);
    floor.render(window);
    player.render(window);

    for (auto& enemy : weakEnemies) {
        enemy.render(window);
    }
}
