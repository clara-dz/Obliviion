#pragma once

#include <SFML/Graphics.hpp>
#include "Fase.h"
#include "JardimDoEden.h"
#include "Menu.h"
#include "Jogador.h"
#include "GerenciadorGrafico.h"
#include "PlayerMode.h"
#include "TelaGameOver.h"


enum class GameState {
    StartMenu,
    Playing,
    GameOver,
    Victory,
    NextLevel
};

class Game {
    public:
        Game();
        ~Game();
        
        PlayerMode playerMode = PlayerMode::SinglePlayer;
        
        void run();
        
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