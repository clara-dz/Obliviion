#include "Jogador.h"

class gardenOfEden : public Fase {
    private:
        Jogador player;

    public:
        gardenOfEden(const std::string& name, const std::string& bgTextureFile, const sf::Texture& playerTexture)
            : Fase(name), player(playerTexture) {
            loadBackgroundTexture(bgTextureFile);
        }

    void loadLevel() override {
        // Load enemies, obstacles etc.
    }

    void update() override {
        player.update(); // let player decide how to move
    }

    void render(sf::RenderWindow& window) override {
        drawBackground(window);
        player.render(window);
        // draw enemies, floor, etc.
    }
};
