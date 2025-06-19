#pragma once

#include "Projetil.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
#include "Inimigo.h"
#include "Jogador.h"

class GerenciadorProjeteis {
private:
    Listas::ListaEntidades listaProjeteis;

public:
    GerenciadorProjeteis() = default;
    ~GerenciadorProjeteis() = default;

    void adicionarProjetil(Projetil* pProj);
    void atualizar(float deltaTime);
    void renderizar(sf::RenderWindow& window);

    void checarColisoes(std::vector<Inimigo*>& inimigos, Jogador* pJog1, Jogador* pJog2);
};
