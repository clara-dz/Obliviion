#pragma once

#include <vector>
#include "Jogador.h"
#include "Floor.h"

class GerenciadorColisoes {
public:
    void checarColisoes(Jogador& player, const Floor& floor);
};
