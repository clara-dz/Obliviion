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
        const int maxInimigosFracos = 7;    
        const int maxIniminMedio = 5;
        const int maxBosses = 0; //não cria boss

        PlayerMode mode = PlayerMode::SinglePlayer;

        Floor floor;

        std::vector<EmoGirl> weakEnemies;
        sf::Texture EmoGirlTexture;

        std::vector<EmoBoy> mediumEnemies;
        sf::Texture emoBoyTexture;
        
        std::vector<EmoBoss> bosses; //está na lógica de verificação
        sf::Texture emoBossTexture;

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
        JardimDoEden(Jogador* j1, Jogador* j2);

        ~JardimDoEden();

        json salvar() const override;

        void loadLevel() override;
        
        void executar(float deltaTime) override;

        void renderizar(sf::RenderWindow& window) override;

        int getPontuacaoTotalJogadores() const override;

        bool todosInimigosMortos() const;

        bool jogadoresMortos() const override;

        void reset();
};
