#pragma once
#include "Entidade.h"
#include "Jogador.h"


class Obstaculo : public Entidade {
protected:
    bool danoso;

public:
    sf::RectangleShape hitbox; // Hitbox do obstáculo

    Obstaculo() = default;
    virtual ~Obstaculo() = default;

    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }

    virtual void afetar(Jogador& jogador) = 0;

    virtual void executar(float deltaTime) override = 0;
    virtual void salva() = 0; // Para o sistema de save futuro
};
