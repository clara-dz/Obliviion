#include "Ente.h"

int Ente::id_contador = 0;

Ente::Ente() {
    this->id = id_contador++;
}

Ente::~Ente() {}

void Ente::setGG(Gerenciadores::GerenciadorGrafico* pGG) {
    Gerenciadores::GerenciadorGrafico* pG = pGG;
}
