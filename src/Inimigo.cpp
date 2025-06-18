#include "Inimigo.h"
#include "Jogador.h"


void Inimigo::danificar(Jogador& p) {
    if (!p.isFlashingNow()) {
        p.tomarDano(nivelMaldade);
    }
};
