#include "GerenciadorColisoes.h"

void GerenciadorColisoes::checarColisoes(Personagem& personagem, const Floor& floor, const std::vector<Obstaculos::Plataforma>& plataformas) {
    sf::FloatRect characterBounds = personagem.getBounds();

    // First check collision with the floor
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

    // Now check collision with each platform
    for (const auto& platform : plataformas) {
        for (const auto& tileBounds : platform.getBounds()) {
            if (characterBounds.intersects(tileBounds)) {
                if (personagem.getVelocityY() > 0.f) {
                    float overlap = (characterBounds.top + characterBounds.height) - tileBounds.top;
                    personagem.move({0.f, -overlap});
                    personagem.stopFalling();
                }
                return;
            }
        }
    }

    personagem.startFalling();
}

void GerenciadorColisoes::checarColisaoEntrePersonagens(Personagem& p1, Personagem& p2) {
    sf::FloatRect bounds1 = p1.getBounds();
    sf::FloatRect bounds2 = p2.getBounds();

    if (bounds1.intersects(bounds2)) {
        float knockbackSpeed = 500.f;
        float overlapX = (bounds1.left + bounds1.width / 2.f) - (bounds2.left + bounds2.width / 2.f);
        float direction = (overlapX > 0.f) ? 1.f : -1.f;

        p1.setVelocityX(direction * knockbackSpeed);
        p1.setVelocityY(-15.f);
        p1.setKnockbackTimer(30.f);

        p2.setVelocityX(-direction * knockbackSpeed * 0.01f);

    }
}
