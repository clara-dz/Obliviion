#include "GerenciadorColisoes.h"


void GerenciadorColisoes::checarColisoes(Jogador& jogador, const Floor& floor) {
    sf::FloatRect playerBounds = jogador.getBounds();

    for (const auto& tileBounds : floor.getBounds()) {
        if (playerBounds.intersects(tileBounds)) {
            if (jogador.getVelocityY() > 0.f) { // only correct if falling
                float overlap = (playerBounds.top + playerBounds.height) - tileBounds.top;
                jogador.move({0.f, -overlap});
                jogador.stopFalling();
            }
            return;
        }
    }

    // No collision this frame → start falling
    jogador.startFalling();
}
