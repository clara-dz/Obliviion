#pragma once

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include "GerenciadorColisoes.h"
#include "ListaEntidades.h"

using json = nlohmann::json;


namespace Fases {

    class Fase {
        protected:
            bool isCompleted;

            std::string levelName;

            sf::Texture backgroundTexture;
            sf::Sprite backgroundSprite;

            std::vector<Entidades::Obstaculos::Obstaculo*> obstaculos;
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
            virtual void reset() = 0;
            virtual void removeInimigos() = 0;
            virtual void carregar(json saveData) = 0;

            virtual bool todosInimigosMortos() const = 0;
            virtual bool jogadoresMortos() const = 0;

            virtual json salvar() const = 0;

            virtual int getPontuacaoTotalJogadores() const = 0;

            // Getters and setters for level name and completion state
            std::string getLevelName() const;
            bool getIsCompleted() const;
            void setCompleted(bool completed);

            // Common method to load background texture
            void loadBackgroundTexture(const std::string& textureFile);
            void drawBackground(sf::RenderWindow& window);
    };
}