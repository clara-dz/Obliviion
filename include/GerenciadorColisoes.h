#pragma once

#include <vector>
#include <list>
#include <set>

// Forward declarations
class Jogador;
class Inimigo;
class Obstaculo;
class Projetil;
class Entidade;

namespace Gerenciadores {

    class GerenciadorColisoes {
    private:
        static GerenciadorColisoes* instancia;

        Jogador* pJog1;
        Jogador* pJog2;

        std::vector<Inimigo*>   listaInimigos;
        std::list<Obstaculo*>   listaObstaculos;
        std::set<Projetil*>     listaProjeteis;

        GerenciadorColisoes();

        const bool verificarColisao(Entidade* pE1, Entidade* pE2);
        void tratarColisaoJogadoresInimigos();
        void tratarColisaoJogadoresObstaculos();
        void tratarColisaoJogadoresProjeteis();
        // Futura colisão: Jogador vs Jogador
        void tratarColisaoEntreJogadores();

    public:
        ~GerenciadorColisoes();
        static GerenciadorColisoes* getInstance();
        
        void setJogadores(Jogador* jogador1, Jogador* jogador2 = nullptr);

        void incluirInimigo(Inimigo* pInim);
        void incluirObstaculo(Obstaculo* pObs);
        void incluirProjetil(Projetil* pProj);

        void executar();
        void limparListas();
    };

}