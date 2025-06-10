#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


class Menu {
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
    void draw(sf::RenderWindow& window);

private:
    void updateVisual();
};
