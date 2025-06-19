#pragma once
#include "Entidade.h"


// TODO: Descobrir como colocar em um namespace
class Obstaculo : public Entidade {
protected:
    bool danoso; // Flag para indicar se o obstáculo causa dano

public:
    sf::RectangleShape hitbox; // Hitbox do obstáculo

    Obstaculo();
    virtual ~Obstaculo();
    // Métodos virtuais puros que as classes filhas DEVERÃO implementar
    // Note que estamos usando os nomes da nossa arquitetura base
    virtual void executar(float deltaTime) override = 0;
    virtual void salva() = 0; // Para o sistema de save futuro
};
