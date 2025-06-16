#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Floor {
private:
    std::vector<sf::Sprite> tiles;
    sf::Texture tileTexture;
    int tileWidth;

public:
    Floor(const std::string& tileTextureFile, int windowWidth, int yPosition) {
        if (!tileTexture.loadFromFile(tileTextureFile)) {
            std::cerr << "Failed to load floor tile texture\n";
        }

        tileWidth = tileTexture.getSize().x;
        int numTiles = windowWidth / tileWidth + 1;

        for (int i = 0; i < numTiles; ++i) {
            sf::Sprite tile(tileTexture);
            tile.setPosition(i * tileWidth, yPosition);
            tiles.push_back(tile);
        }
    }

    void renderizar(sf::RenderWindow& window) const {
        for (const auto& tile : tiles) {
            window.draw(tile);
        }
    }

    // Optional: for collision detection
    std::vector<sf::FloatRect> getBounds() const {
        std::vector<sf::FloatRect> bounds;
        for (const auto& tile : tiles) {
            bounds.push_back(tile.getGlobalBounds());
        }
        return bounds;
    }
};
