#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "GerenciadorColisoes.h"


class Fase {
    protected:
        std::string levelName;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        bool isCompleted;

        GerenciadorColisoes colisor;

    public:
        Fase(const std::string& name) 
            : levelName(name), isCompleted(false) {}

        virtual ~Fase() {}

        // Pure virtual function to load the level's specific resources
        virtual void loadLevel() = 0;

        // Pure virtual function to update the level's state
        virtual void executar(float deltaTime) = 0;

        // Pure virtual function to render the level's objects
        virtual void render(sf::RenderWindow& window) = 0;

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
