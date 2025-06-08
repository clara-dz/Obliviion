#include "GerenciadorColisoes.h"

void GerenciadorColisoes::checarColisoes(Personagem& personagem, const Floor& floor) {
    sf::FloatRect characterBounds = personagem.getBounds();

    for (const auto& tileBounds : floor.getBounds()) {
        if (characterBounds.intersects(tileBounds)) {
            if (personagem.getVelocityY() > 0.f) {
                float overlap = (characterBounds.top + characterBounds.height) - tileBounds.top;
                personagem.move({0.f, -overlap});
                personagem.stopFalling();
            }
            return;
        }
    }

    personagem.startFalling();
}

void GerenciadorColisoes::checarColisaoEntrePersonagens(Personagem& p1, Personagem& p2) {
    sf::FloatRect bounds1 = p1.getBounds();
    sf::FloatRect bounds2 = p2.getBounds();

    if (bounds1.intersects(bounds2)) {
        // Calculate overlap
        float overlapX = (bounds1.left + bounds1.width / 2) - (bounds2.left + bounds2.width / 2);
        float pushback = (overlapX > 0) ? 10.f : -10.f; // push direction

        // Apply knockback to p1 only
        p1.move({pushback, 0.f});

        // Optional: reposition to prevent overlap more precisely
        sf::FloatRect updatedBounds = p1.getBounds();
        if (updatedBounds.intersects(bounds2)) {
            float penetration = (overlapX > 0) ?
                (updatedBounds.left + updatedBounds.width) - bounds2.left :
                bounds2.left + bounds2.width - updatedBounds.left;

            p1.move({(overlapX > 0 ? -penetration : penetration), 0.f});
        }

        // Optionally call p1.takeDamage() or play sound/effects
    }
}
