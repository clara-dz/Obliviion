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

json Fase::salvar(json data) const {
    data["Nome"] = levelName;
    return data;
}