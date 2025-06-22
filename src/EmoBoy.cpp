#include "EmoBoy.h"
#include <cstdlib> 
#include <ctime> 


EmoBoy::EmoBoy(int x, int y, int speed, const sf::Texture& texture)
    : Inimigo(x, y, speed) {
    nivelMaldade = 2; //o dobro do inimigo fraco
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    startFalling();
    numVidas = 2;
    sprite.setTexture(texture);
}


void EmoBoy::executar(float deltaTime) {
    applyGravity(deltaTime);

    if (pJog1->isAlive){
        attackPlayer(deltaTime, pJog1);
    }
    if (pJog2->isAlive){
        attackPlayer(deltaTime, pJog2);
    }
}

void EmoBoy::attackPlayer(float deltaTime, Jogador* pJogador) {
    // deltaTime *= tamanho;
    sf::Vector2f playerPos = pJogador->getPosition();
    sf::Vector2f myPos = sprite.getPosition();

    float distance = std::abs(playerPos.x - myPos.x);

    // If player is within detection radius, follow
    if (distance <= detectionRadius && distance > 5.f) {
        float direction = (playerPos.x < myPos.x) ? -1.f : 1.f;
        sprite.move(direction * speed * deltaTime, 0.f);
    } 
    // Otherwise, random lateral movement
    else {
        lateralWiggleTimer += deltaTime;
        if (lateralWiggleTimer >= lateralWiggleDuration) {
            // Change direction randomly every few seconds
            lateralWiggleDirection = (rand() % 3) - 1; // -1, 0, or 1
            lateralWiggleTimer = 0.f;
            lateralWiggleDuration = 0.5f + static_cast<float>(rand() % 100) / 10.f; // 0.5 to 1.5 sec
        }

        sprite.move(lateralWiggleDirection * speed * 0.5f * deltaTime, 0.f); // slower wiggle
    }
}

void EmoBoy::setJogadores(Jogador* j1, Jogador* j2) {
        pJog1 = j1;
        pJog2 = j2;
    }