#include "Ente.h"

int Ente::id_count = 0;

Ente::Ente() {
    this->id = id_count++;
}

Ente::~Ente() {}


