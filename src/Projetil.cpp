#include "Projetil.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


json Entidades::Projetil::salvar() {
    json data;
    
    data["posicao"] = { sprite.getPosition().x, sprite.getPosition().y };
    data["velocidade"] = { velocidade.x, velocidade.y };
    data["dono"] = static_cast<int>(dono);
    data["tempoDeVida"] = tempoDeVida;
    data["ativo"] = ativo;
    
    return data;
}