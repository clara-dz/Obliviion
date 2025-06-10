#include "Menu.h"

Menu::Menu(const std::vector<std::string>& itemLabels, const sf::Font& loadedFont)
    : items(itemLabels), font(loadedFont), selectedIndex(0), isOpen(false) {

    for (const auto& label : items) {
        sf::Text text(label, font, 32);
        text.setFillColor(sf::Color::White);
        texts.push_back(text);
    }

    for (std::size_t i = 0; i < texts.size(); ++i) {
        texts[i].setPosition(300.f, 180.f + i * 50.f);
    }

    // Set up background box
    backgroundBox.setSize(sf::Vector2f(300.f, items.size() * 50.f + 40.f));
    backgroundBox.setFillColor(sf::Color(0, 0, 0, 180));  // semi-transparent black
    backgroundBox.setOutlineThickness(2.f);
    backgroundBox.setOutlineColor(sf::Color::White);
    backgroundBox.setPosition(280.f, 160.f);

    updateVisual();
}


void Menu::open() {
    isOpen = true;
}

void Menu::close() {
    isOpen = false;
}

bool Menu::isOpened() const {
    return isOpen;
}

void Menu::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Up:
                if (selectedIndex > 0) selectedIndex--;
                updateVisual();
                break;
            case sf::Keyboard::Down:
                if (selectedIndex < items.size() - 1) selectedIndex++;
                updateVisual();
                break;
            case sf::Keyboard::Enter:
                if (items[selectedIndex] == "Sair") {
                    window.close();
                }
                break;
            default:
                break;
        }
    }
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(backgroundBox);
    for (auto& text : texts) {
        window.draw(text);
    }
}

void Menu::updateVisual() {
    for (std::size_t i = 0; i < texts.size(); ++i) {
        texts[i].setFillColor(i == selectedIndex ? sf::Color::Yellow : sf::Color::White);
    }
}
