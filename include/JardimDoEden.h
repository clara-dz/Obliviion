#pragma once

#include "Jogador.h"
#include "Fase.h"
#include "Floor.h"
#include "InimigoFraco.h"
#include "ObstaculoMedio.h"
#include <vector>
#include <SFML/Graphics.hpp>


class JardimDoEden : public Fase {
    private:
        const int maxIniminMedio = 10;
        Floor floor;
        Jogador player;
        std::vector<InimigoFraco> weakEnemies;
        std::vector<Obst_Medio> ObsMedio;
        sf::Texture inimigoFracoTexture;

    protected:
        void criarInimMedios();
        void criarObsMedios();
        void criarInimFracos();
        void criarObsFracos();
    public:
        JardimDoEden(const std::string& name,
                     const std::string& tileTexture,
                     const std::string& bgTextureFile,
                     const sf::Texture& playerTexture,
                     int windowWidth);

        void loadLevel() override;
        void executar(float deltaTime) override;
        void renderizar(sf::RenderWindow& window) override;
};
