#include "Fase.h"


Fases::Fase::~Fase() {
    for (auto* obstaculo : obstaculos) {
        delete obstaculo; // Clean up dynamically allocated obstacles
    }
    obstaculos.clear();
    if (colisor) {
        colisor->resetar(); // Reset collision manager
    }
}


std::string Fases::Fase::getLevelName() const { return levelName; }
bool Fases::Fase::getIsCompleted() const { return isCompleted; }
void Fases::Fase::setCompleted(bool completed) { isCompleted = completed; }


void Fases::Fase::loadBackgroundTexture(const std::string& textureFile) {
    if (!backgroundTexture.loadFromFile(textureFile)) {
        std::cerr << "Failed to load texture: " << textureFile << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
}

void Fases::Fase::drawBackground(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}
