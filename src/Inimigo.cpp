#pragma once
#include "Inimigo.h"
#include <fstream>
#include <iostream>

int nivel_maldade = 0;
int hp = 0;

Inimigo::Inimigo() {}

Inimigo::~Inimigo() {}

void Inimigo::salvarDataBuffer() { //verificar se está correto

    std::ofstream file("inimigo_dados.txt", std::ios::app);
    if (file.is_open()) {
        file << "HP: " << hp << ", Pos: (" << x << ", " << y << ")\n"; //hit points
        file.close();
    } else {
        std::cerr << "Erro ao salvar os dados do inimigo.\n";
    }
}



