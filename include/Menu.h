#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Ente.h"

class Menu : public Ente {
private:
    std::vector<std::string> items;
    std::vector<sf::Text> texts;
    sf::Font font;
    std::size_t selectedIndex;
    bool isOpen;

    sf::RectangleShape backgroundBox;

public:
    Menu(const std::vector<std::string>& itemLabels, const sf::Font& font);

    void open();
    void close();
    bool isOpened() const;

    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    
    // Required overrides from Ente
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    void updateVisual();
};
