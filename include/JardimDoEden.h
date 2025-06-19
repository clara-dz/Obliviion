#pragma once

// using namespace Obstaculos;

#include <SFML/Graphics.hpp>
#include <vector>

#include "Jogador.h"
#include "Fase.h"
#include "Floor.h"
#include "InimigoFraco.h"
#include "ObstaculoMedio.h"
#include "Plataforma.h"

class JardimDoEden : public Fase {
    private:
        const int maxIniminMedio = 10;
        Floor floor;
        Jogador player;

        std::vector<InimigoFraco> weakEnemies;
        std::vector<Obst_Medio> ObsMedio;
        sf::Texture inimigoFracoTexture;
        sf::Texture texProjJogador;

        std::vector<Obstaculos::Plataforma> plataformas;
        sf::Texture plataformaEsqTex, plataformaDirTex, plataformaMeioTex;


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
