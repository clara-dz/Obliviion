#pragma once

#include <vector>
#include <list>
#include <set>

#include "Jogador.h"
#include "Floor.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "Entidade.h"
#include "Plataforma.h"


class GerenciadorColisoes {
    static GerenciadorColisoes* instancia;
        Jogador* pJog1;
        Jogador* pJog2;
        std::vector<Inimigo*>   listaInimigos;
        std::list<Obstaculo*>   listaObstaculos;
        std::set<Projetil*>     listaProjeteis;
        // GerenciadorColisoes();

    public:
        void checarColisoes(Personagem& Personagem, const Floor& floor, const std::vector<Obstaculos::Plataforma>& plataformas);
        void checarColisaoEntrePersonagens(Personagem& p1, Personagem& p2);
        void incluirInimigo(Inimigo* pI);
        void incluirObstaculo(Obstaculo* pO);
        void incluirProjetil(Projetil* pJ);
        void tratarColisaoJogsInimigs();
        void executar();

    private:
        const bool verificarColisao(Personagem& p1, Personagem& p2);
        void tratarColisaoJogsObstacs();
        void tratarColisaoJogsProjeteis();
};

