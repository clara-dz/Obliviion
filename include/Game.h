#pragma once

#include <SFML/Graphics.hpp>
#include "Fase.h"
#include "JardimDoEden.h"
#include "Menu.h"
#include "Jogador.h"
#include "GerenciadorGrafico.h"


enum class GameState {
    Playing,
    GameOver,
    Victory,
    NextLevel
};

class Game {
    public:
        Game();
        ~Game();
        void run();
        
    private:
        GameState gameState = GameState::Playing;
        // Jogador pJog1;
        // Gerenciadores::GerenciadorGrafico GG;
        sf::RenderWindow window;
        Fase* currentLevel;
        sf::Clock clock;
        Menu* menu;
        sf::Font font;

        void processEvents();
        void executar();
        void renderizar();
};