#pragma once
#include "Personagem.h"
#include "Jogador.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


class Inimigo : public Personagem {
    protected:
        int nivelMaldade;
    public:
        Inimigo() : Personagem() {}
        Inimigo(int x, int y, int speed) : Personagem(x, y, speed) {}
        virtual ~Inimigo() = default;
        virtual void danificar(Jogador& p);
        json salvar();

        virtual void executar(float deltaTime) = 0;
};