#pragma once

#include "Jogador.h"
#include "Fase.h"
#include "Floor.h"
#include "InimigoFraco.h"
#include "ObstaculoMedio.h"
#include <vector>
#include <SFML/Graphics.hpp>


class GardenOfEden : public Fase {
private:
    Floor floor;
    Jogador player;
    std::vector<InimigoFraco> weakEnemies;
    std::vector<Obst_Medio> ObsMedio;
    sf::Texture inimigoFracoTexture;

public:
    GardenOfEden(const std::string& name,
                 const std::string& tileTexture,
                 const std::string& bgTextureFile,
                 const sf::Texture& playerTexture,
                 int windowWidth);

    void loadLevel() override;
    void executar(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};
