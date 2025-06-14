#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "Inimigo.h"

Gerenciadores::GerenciadorColisoes* Gerenciadores::GerenciadorColisoes::instancia = nullptr;

namespace Gerenciadores {

    GerenciadorColisoes* GerenciadorColisoes::getInstance() {
        if (instancia == nullptr) {
            instancia = new GerenciadorColisoes();
        }
        return instancia;
    }

    GerenciadorColisoes::GerenciadorColisoes() : pJog1(nullptr), pJog2(nullptr) {
    }

    GerenciadorColisoes::~GerenciadorColisoes() {
        limparListas();
    }

    void GerenciadorColisoes::setJogadores(Jogador* jogador1, Jogador* jogador2) {
        pJog1 = jogador1;
        pJog2 = jogador2;
    }

    void GerenciadorColisoes::incluirInimigo(Inimigo* pInim) {
        if (pInim) listaInimigos.push_back(pInim);
    }
    

    void GerenciadorColisoes::executar() {
        tratarColisaoJogadoresInimigos();
        tratarColisaoEntreJogadores(); 
    }

    const bool GerenciadorColisoes::verificarColisao(Entidade* pE1, Entidade* pE2) {
        if (pE1 == nullptr || pE2 == nullptr) return false;
        return pE1->getBounds().intersects(pE2->getBounds());
    }

    void GerenciadorColisoes::tratarColisaoJogadoresInimigos() {
        for (Inimigo* inim : listaInimigos) {
            // Verifica a colisão com o jogador 1, se ele existir
            if (verificarColisao(pJog1, inim)) {
                pJog1->handleCollision(*inim);
                inim->handleCollision(*pJog1);
            }
            // Verifica a colisão com o jogador 2, se ele existir
            if (verificarColisao(pJog2, inim)) {
                pJog2->handleCollision(*inim);
                inim->handleCollision(*pJog2);
            }
        }
    }
    
    void GerenciadorColisoes::tratarColisaoEntreJogadores() {
        // Só verifica se ambos os jogadores existem
        if (verificarColisao(pJog1, pJog2)) {
            pJog1->handleCollision(*pJog2);
            pJog2->handleCollision(*pJog1);
        }
    }

    // Implementação pendente das outras funções de tratamento
    void GerenciadorColisoes::tratarColisaoJogadoresObstaculos() { /* ... */ }
    void GerenciadorColisoes::tratarColisaoJogadoresProjeteis() { /* ... */ }

    void GerenciadorColisoes::limparListas() {
        pJog1 = nullptr;
        pJog2 = nullptr;
        listaInimigos.clear();
        listaObstaculos.clear();
        listaProjeteis.clear();
    }
}