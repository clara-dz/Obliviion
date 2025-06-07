#pragma once
#include "Jogador.h"
#include "Fase.h"
#include "Floor.h"


class gardenOfEden : public Fase {
    private:
        Floor floor;
        Jogador player;

    public:
        gardenOfEden(const std::string& name, const std::string& tileTexture, const std::string& bgTextureFile, const sf::Texture& playerTexture, int windowWidht)
            : Fase(name), floor(tileTexture, windowWidht, 500), player(playerTexture) {
            loadBackgroundTexture(bgTextureFile);
        }

    void loadLevel() override {
        // Load enemies, obstacles etc.
    }

    void update(float deltaTime) override {
        player.update(deltaTime);
        colisor.checarColisoes(player, floor);
    }

    void render(sf::RenderWindow& window) override {
        drawBackground(window);
        floor.render(window);
        player.render(window);
        // draw enemies, floor, etc.
    }
};
