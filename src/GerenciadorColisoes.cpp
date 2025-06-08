#include "GerenciadorColisoes.h"

void GerenciadorColisoes::checarColisoes(Personagem& personagem, const Floor& floor) {
    sf::FloatRect characterBounds = personagem.getBounds();

    for (const auto& tileBounds : floor.getBounds()) {
        if (characterBounds.intersects(tileBounds)) {
            if (personagem.getVelocityY() > 0.f) { // only correct if falling
                float overlap = (characterBounds.top + characterBounds.height) - tileBounds.top;
                personagem.move({0.f, -overlap});
                personagem.stopFalling();
            }
            return;
        }
    }

    // No collision this frame → start falling
    personagem.startFalling();
}
