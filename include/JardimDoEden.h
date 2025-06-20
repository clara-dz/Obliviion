#pragma once

// using namespace Obstaculos;

#include <SFML/Graphics.hpp>
#include <vector>

#include "Fase.h"
#include "Floor.h"
#include "InimigoMedio.h"
#include "InimigoFraco.h"
#include "Jogador.h"
#include "ObstaculoMedio.h"
#include "Plataforma.h"
#include "PlayerMode.h"


class JardimDoEden : public Fase {
    private:
        const int maxIniminMedio = 10;
        PlayerMode mode = PlayerMode::SinglePlayer;

        Floor floor;
        Jogador player;
        Jogador player2;

        std::vector<InimigoFraco> weakEnemies;
        std::vector<InimigoMedio> mediumEnemies;
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
                     const sf::Texture& player2Texture,
                     int windowWidth,
                     PlayerMode mode);

        void loadLevel() override;
        void executar(float deltaTime) override;
        void renderizar(sf::RenderWindow& window) override;

        bool todosInimigosMortos() const {
            for (const auto& enemy : weakEnemies) {
                if (enemy.estaVivo()) return false;
            }
            return true;
        }

        bool jogadoresMortos() {
            return (!player.estaVivo() && !player2.estaVivo());
        }
};
