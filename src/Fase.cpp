#include <nlohmann/json.hpp>
#include "Fase.h"

using json = nlohmann::json;


Fase::~Fase() {
    for (auto* obstaculo : obstaculos) {
        delete obstaculo; // Clean up dynamically allocated obstacles
    }
    obstaculos.clear();
    if (colisor) {
        colisor->resetar(); // Reset collision manager
    }
}

json Fase::salvar() const {
    json data;
    // (Opcional) adicionar conteúdo básico
    data["tipo"] = "Fase";
    return data;
}