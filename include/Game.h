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
    protected:
        Jogador* pJog1;
        Jogador* pJog2;
    public:
        Game();
        ~Game();
        
        PlayerMode playerMode = PlayerMode::SinglePlayer;
        
        void run();
        void salvarJogo();
        void carregarJogo();

        void salvarDataBuffer(json saveData);
        void iniciarFase(std::string NomeFase);
        
    private:
        sf::Texture playerTexture;
        sf::Texture player2Texture;
        sf::Texture texProjJogador;
        

        GameState gameState = GameState::StartMenu;
        TelaGameOver telaGameOver;

        // Gerenciadores::GerenciadorGrafico GG;
        Fase* currentLevel;
        std::string currentLevelName;
        Menu* menu;
        
        sf::RenderWindow window;
        sf::Clock clock;
        sf::Font font;

        void processarTelaGameOver();
        void processEvents();
        void executar();
        void renderizar();
        void salvarPontuacao(const std::string& nome, int pontos);
        void trocarFase();
        void carregarJogadores(json saveData);
};