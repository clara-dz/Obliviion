#include "EmoBoss.h"
#include "Config.h"
#include "GerenciadorColisoes.h"

extern const unsigned int SCREEN_WIDTH;

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
    
    if (pJog1->isAlive){
        attackPlayer(deltaTime, pJog1);
    }
    if (pJog2->isAlive){
        attackPlayer(deltaTime, pJog2);
    }


    if (isFlashing && flashClock.getElapsedTime().asSeconds() > flashDuration) {
        sprite.setColor(sf::Color::White);  // Reset to normal
        isFlashing = false;
    }
}

void EmoBoss::attackPlayer(float deltaTime, Jogador* pJogadorAlvo) {
    sf::Vector2f playerPos = pJogadorAlvo->getPosition();
    sf::Vector2f myPos = sprite.getPosition();

    float distanceX = playerPos.x - myPos.x;
    float absDistanceX = std::abs(distanceX);

    // Stay at least 200 units away from the player
    const float safeDistance = 200.f;

    if (absDistanceX < safeDistance) {
        // Move away from player
        float direction = (distanceX < 0) ? 1.f : -1.f;
        float nextX = myPos.x + direction * speed * deltaTime;

        // Keep within screen bounds
        if (nextX >= 0 && nextX <= SCREEN_WIDTH - sprite.getGlobalBounds().width) {
            sprite.move(direction * speed * deltaTime, 0.f);
        }
    }

    // Shooting logic
    if (shootClock.getElapsedTime().asSeconds() >= shootCooldown) {
        Entidades::Projetil* proj = atirar();
        GerenciadorColisoes::getInstancia()->incluirProjetil(proj);

        shootClock.restart();
    }
}

Entidades::Projetil* EmoBoss::atirar() {
    std::cout << "Big Boss Shooting\n";

    sf::Vector2f vel = { -10.f, 0.f };
    return new Entidades::Projetil(*texProjetil, sprite.getPosition(), vel, Dono::Inimigo);
}

void EmoBoss::setTexProjetil(const sf::Texture* tex) {
    texProjetil = tex;
}

void EmoBoss::setJogadores(Jogador* j1, Jogador* j2) {
        pJog1 = j1;
        pJog2 = j2;
}