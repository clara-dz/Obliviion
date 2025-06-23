#pragma once

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include "GerenciadorColisoes.h"
#include "ListaEntidades.h"

using json = nlohmann::json;


class Fase {
    protected:
        bool isCompleted;

        std::string levelName;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

        std::vector<Obstaculo*> obstaculos;
        sf::Texture barrierTex, fireTex;
        
        GerenciadorColisoes* colisor = GerenciadorColisoes::getInstancia(); //Singleton, para evitar conflito (ter várias instâncias)

    public:
        Jogador* pJog1;
        Jogador* pJog2;
        Fase(const std::string& name, Jogador* j1, Jogador* j2) 
            : levelName(name), isCompleted(false), pJog1(j1), pJog2(j2) {}

        virtual ~Fase();

        virtual void loadLevel() = 0;
        virtual void executar(float deltaTime) = 0;
        virtual void renderizar(sf::RenderWindow& window) = 0;
        virtual bool todosInimigosMortos() const = 0;
        virtual bool jogadoresMortos() const = 0;
        virtual json salvar() const = 0;
        virtual void reset() = 0;
        
        virtual int getPontuacaoTotalJogadores() const = 0;
        
        // Getters and setters for level name and completion state
        std::string getLevelName() const { return levelName; }
        bool getIsCompleted() const { return isCompleted; }
        void setCompleted(bool completed) { isCompleted = completed; }

        // Common method to load background texture
        void loadBackgroundTexture(const std::string& textureFile) {
            if (!backgroundTexture.loadFromFile(textureFile)) {
                std::cerr << "Failed to load texture: " << textureFile << std::endl;
            }
            backgroundSprite.setTexture(backgroundTexture);
        }

        void drawBackground(sf::RenderWindow& window) {
            window.draw(backgroundSprite);
        }
};
