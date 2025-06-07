#include "GerenciadorColisoes.h"


void GerenciadorColisoes::checarColisoes(Jogador& jogador, const Floor& floor) {
    sf::FloatRect playerBounds = jogador.getBounds();

    for (const auto& tileBounds : floor.getBounds()) {
        if (playerBounds.intersects(tileBounds)) {
            // Simple resolution: push the player up until it no longer intersects
            float overlap = (playerBounds.top + playerBounds.height) - tileBounds.top;
            jogador.move(sf::Vector2f(0.f, -overlap));
        }
    }
}
