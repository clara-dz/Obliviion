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
    if (!inimigoTexture.loadFromFile("../assets/images/inimigo_fraco.png")) {
        std::cerr << "Error loading enemy texture!\n";
    }
}

void GardenOfEden::loadLevel() {
    // Example: load 5 enemies in specific positions
    // for (int i = 0; i < 5; ++i) {
    //     InimigoFraco enemy(inimigoTexture, 100 + i * 150, 400);
    //     enemies.push_back(enemy);
    // }
}

void GardenOfEden::update(float deltaTime) {
    player.update(deltaTime);
    colisor.checarColisoes(player, floor);

    // for (auto& enemy : enemies) {
    //     enemy.update(deltaTime);
    //     colisor.checarColisoes(enemy, floor);
    // }
}

void GardenOfEden::render(sf::RenderWindow& window) {
    drawBackground(window);
    floor.render(window);
    player.render(window);

    // for (auto& enemy : enemies) {
    //     enemy.render(window);
    // }
}
