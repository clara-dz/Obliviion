#include "Fase.h"


Fases::Fase::~Fase() {
    for (auto* obstaculo : obstaculos) {
        delete obstaculo; // Clean up dynamically allocated obstacles
    }
    obstaculos.clear();
    if (colisor) {
        colisor->resetar(); // Reset collision manager
    }
}
