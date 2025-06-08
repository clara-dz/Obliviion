#pragma once

#include "Jogador.h"
#include "Fase.h"
#include "Floor.h"
#include "InimigoFraco.h"
#include <vector>
#include <SFML/Graphics.hpp>


class GardenOfEden : public Fase {
private:
    Floor floor;
    Jogador player;
    std::vector<InimigoFraco> weakEnemies;
    sf::Texture inimigoFracoTexture;

public:
    GardenOfEden(const std::string& name,
                 const std::string& tileTexture,
                 const std::string& bgTextureFile,
                 const sf::Texture& playerTexture,
                 int windowWidth);

    void loadLevel() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};
