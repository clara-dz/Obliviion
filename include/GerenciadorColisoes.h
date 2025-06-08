#pragma once

#include <vector>
#include "Jogador.h"
#include "Floor.h"

class GerenciadorColisoes {
public:
    void checarColisoes(Personagem& Personagem, const Floor& floor);
};
