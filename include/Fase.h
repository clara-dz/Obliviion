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
        sf::Texture smokeTex, fireTex;
        
        // virtual void criarObstaculos() = 0;
        GerenciadorColisoes* colisor = GerenciadorColisoes::getInstancia();

    public:
        Fase(const std::string& name) 
            : levelName(name), isCompleted(false) {}

        virtual ~Fase();

        virtual void loadLevel() = 0;
        virtual void executar(float deltaTime) = 0;
        virtual void renderizar(sf::RenderWindow& window) = 0;
        virtual bool todosInimigosMortos() const = 0;
        virtual bool jogadoresMortos() const = 0;
        virtual json salvar(json data) const;

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
