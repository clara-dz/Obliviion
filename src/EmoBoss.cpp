#include "EmoBoss.h"

EmoBoss::EmoBoss(int x, int y, int speed, const sf::Texture& texture)
: Inimigo(x, y, speed) {

    nivelMaldade = 3; // O triplo do Inimigo fraco
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    startFalling();
    sprite.setTexture(texture);
    numVidas = 3; //o triplo do inimigo fraco
}

void EmoBoss::executar(float deltaTime) {
    applyGravity(deltaTime);
    sprite.move(velocityX * deltaTime, 0.f);
}

Projetil* EmoBoss::atirar() {
    std::cout << "Big Boss Shooting\n";

    sf::Vector2f vel = { 10.f, 0.f };
    return new Projetil(*texProjetil, sprite.getPosition(), vel, Dono::Inimigo);
}

void Jogador::setTexProjetil(const sf::Texture* tex) {
    texProjetil = tex;
}
