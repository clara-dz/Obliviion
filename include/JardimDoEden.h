#pragma once

// using namespace Obstaculos;

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <vector>

#include "Jogador.h"
#include "PlayerMode.h"

#include "Fase.h"
#include "Plataforma.h"
#include "Floor.h"

#include "EmoBoss.h"
#include "EmoBoy.h"
#include "EmoGirl.h"

#include "BarreiraDoLimbo.h"


using json = nlohmann::json;


class JardimDoEden : public Fase {
    private:
        const int maxInimigosFracos = 3;    
        const int maxIniminMedio = 2;
        PlayerMode mode = PlayerMode::SinglePlayer;

        Floor floor;

        std::vector<EmoGirl> weakEnemies;
        sf::Texture EmoGirlTexture;

        std::vector<EmoBoy> mediumEnemies;
        sf::Texture emoBoyTexture;
        
        std::vector<EmoBoss> bosses;
        sf::Texture emoBossTexture;

        std::vector<Obstaculos::Plataforma> plataformas;
        sf::Texture plataformaEsqTex, plataformaDirTex, plataformaMeioTex;

        sf::Texture texProjJogador;

    protected:
        void criarPlataformas();
        void criarObsMedios();
        void criarInimMedios();
        void criarInimFracos();

    public:
        JardimDoEden(Jogador* j1, Jogador* j2);

        json salvar() const override;
        void loadLevel() override;
        
        void executar(float deltaTime) override;
        void renderizar(sf::RenderWindow& window) override;


        int getPontuacaoTotalJogadores() const override {
            return pJog1->getPontos();
        }

        bool todosInimigosMortos() const {
            for (const auto& enemy : weakEnemies) {
                if (enemy.estaVivo()) return false;
            }
            return true;
        }

        bool jogadoresMortos() const override {
            return (!pJog1->estaVivo() && !pJog2->estaVivo());
        }
};
