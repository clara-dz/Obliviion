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

void Entidades::Projetil::executar(float deltaTime) {
    if (!ativo) return;

    tempoDeVida -= deltaTime;
    if (tempoDeVida <= 0.f) {
        desativar();
        return;
    }

    sprite.move(velocidade * deltaTime);
};

sf::FloatRect Entidades::Projetil::getBounds() const {
    return sprite.getGlobalBounds();
}

Dono Entidades::Projetil::getDono() const { return dono; }
bool Entidades::Projetil::estaAtivo() const { return ativo; }
void Entidades::Projetil::desativar() { ativo = false; }
