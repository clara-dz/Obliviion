#include "Inimigo.h"
#include "Jogador.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void Inimigo::danificar(Jogador& p) {
    if (!p.isFlashingNow()) {
        p.tomarDano(nivelMaldade);
    }
};

json Inimigo::salvar() {
    json data;
    data["numVida"] = numVidas;
    data["x"] = x;
    data["y"] = y;
    data["nivelMaldade"] = nivelMaldade;
    return data;
}

