#pragma once

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include "Fase.h"
#include "JardimDoEden.h"
#include "Menu.h"
#include "Jogador.h"
#include "GerenciadorGrafico.h"
#include "PlayerMode.h"
#include "TelaGameOver.h"

using json = nlohmann::json;


enum class GameState {
    StartMenu,
    Playing,
    GameOver,
    Victory,
    NextLevel,
    Ranking
};

class Game {
    public:
        Game();
        ~Game();
        
        PlayerMode playerMode = PlayerMode::SinglePlayer;
        
        void run();
        void salvarJogo();

        void salvarDataBuffer(json saveData);
        
    private:
        GameState gameState = GameState::StartMenu;
        TelaGameOver telaGameOver;

        // Jogador pJog1;
        // Gerenciadores::GerenciadorGrafico GG;
        Fase* currentLevel;
        Menu* menu;
        
        sf::RenderWindow window;
        sf::Clock clock;
        sf::Font font;

        void processarTelaGameOver();
        void processEvents();
        void executar();
        void renderizar();
        void salvarPontuacao(const std::string& nome, int pontos);
};