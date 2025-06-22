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


class InfernoDeDante : public Fase {
    private:
        const int maxInimigosFracos = 1;    //não cria inimigoFraco
        const int maxIniminMedio = 0;
        const int maxBosses = 3;

        PlayerMode mode = PlayerMode::SinglePlayer;

        Floor floor;

        std::vector<EmoGirl> weakEnemies;  //está na lógica de verificação
        sf::Texture EmoGirlTexture;

        std::vector<EmoBoy> mediumEnemies;
        sf::Texture emoBoyTexture;
        
        std::vector<EmoBoss> bosses;
        sf::Texture emoBossTexture;
        sf::Texture emoBossProjTexture;

        std::vector<Obstaculos::Plataforma> plataformas;
        sf::Texture plataformaEsqTex, plataformaDirTex, plataformaMeioTex;

        sf::Texture texProjJogador;

    protected:
        void criarPlataformas();
        void criarObsMedios();
        void criarInimMedios();
        void criarInimFracos();
        void criarBosses();

    public:
        InfernoDeDante(Jogador* j1, Jogador* j2);

        ~InfernoDeDante();

        json salvar() const override;

        void loadLevel() override;
        
        void executar(float deltaTime) override;

        void renderizar(sf::RenderWindow& window) override;

        int getPontuacaoTotalJogadores() const override;

        bool todosInimigosMortos() const;

        bool jogadoresMortos() const override;
};
