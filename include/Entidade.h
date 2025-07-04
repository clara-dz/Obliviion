#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"
#include <iostream>
#include <nlohmann/json.hpp>


using json = nlohmann::json;


namespace Entidades {
    class Entidade : public Ente {
        protected:
            sf::Sprite sprite;
            int x, y;
            bool isVisible;

        public:

            Entidade();           //a classe tem duas funções inicializadoras
            Entidade(int x, int y);

            virtual ~Entidade() {}
            virtual void executar(float deltaTime) override = 0;
            
            void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override;
            void renderizar(sf::RenderWindow& window) override;
            void setSprite(const sf::Texture& texture);
    };
}
