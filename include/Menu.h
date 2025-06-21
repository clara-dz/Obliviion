#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Ente.h"

class Jogo;
class Menu : public Ente {
    private:
        Jogo* pJog;
        bool isOpen;

        std::vector<std::string> items;
        std::vector<sf::Text> texts;
        std::size_t selectedIndex;

        sf::Font font;
        sf::RectangleShape backgroundBox;

    public:
        Menu(const std::vector<std::string>& itemLabels, const sf::Font& font);

        void open();
        void close();
        bool isOpened() const;

        void handleEvent(const sf::Event& event, sf::RenderWindow& window);

        // Required overrides from Ente
        void executar(float deltaTime) override;
        void renderizar(sf::RenderWindow& window) override;
        void desenhar(sf::RenderTarget& target, sf::RenderStates states) const override;
        void resetSelection();

        std::string getSelectedOption() const;

    private:
        void updateVisual();
};
