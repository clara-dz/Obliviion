#include "EmoGirl.h"

EmoGirl::EmoGirl(int x, int y, int speed, const sf::Texture& texture, bool movingLeft)
        : Inimigo(x, y, speed) {
        sprite.setTexture(texture);
        nivelMaldade = 1;  //nível mais baixo de maldade
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        startFalling();
    }

void EmoGirl::executar(float deltaTime) {
    applyGravity(deltaTime);

    float movement = speed * deltaTime;
    
    // Move left or right
    if (movingLeft) {
        sprite.move(-movement, 0.f);
        traveled -= movement;
        if (traveled <= -raio) {
            movingLeft = false; // switch direction
        }
    } else {
        sprite.move(movement, 0.f);
        traveled += movement;
        if (traveled >= raio) {
            movingLeft = true; // switch direction
        }
    }

    if (isFlashing && flashClock.getElapsedTime().asSeconds() > flashDuration) {
        sprite.setColor(sf::Color::White);  // Reset to normal
        isFlashing = false;
    }
}
