#include "JardimDoEden.h"
#include <iostream>

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

    // Add platforms
    plataformas.emplace_back(plataformaEsqTex, plataformaMeioTex, plataformaDirTex, 200.f, 400.f, 3);
    plataformas.emplace_back(plataformaEsqTex, plataformaMeioTex, plataformaDirTex, 500.f, 300.f, 2);

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
