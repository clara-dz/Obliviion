#include "GerenciadorColisoes.h"


void GerenciadorColisoes::checarColisoes(Jogador& jogador, const Floor& floor) {
    sf::FloatRect playerBounds = jogador.getBounds();

    for (const auto& tileBounds : floor.getBounds()) {
        if (playerBounds.intersects(tileBounds)) {
            float overlap = (playerBounds.top + playerBounds.height) - tileBounds.top;
            jogador.move({0.f, -overlap});
            jogador.stopFalling(); // sets velocityY = 0 and isOnGround = true
            return;
        }
    }

    // No collision this frame → start falling
    jogador.startFalling();
}
