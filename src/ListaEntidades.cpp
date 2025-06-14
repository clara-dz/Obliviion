// ListaEntidades.cpp
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>

namespace Listas {
    ListaEntidades::ListaEntidades() {}
    ListaEntidades::~ListaEntidades() {
        limpar();
    }

    // Simplesmente repassa o ponteiro para a nossa lista genérica.
    void ListaEntidades::incluir(Entidade* pE) {
        if (pE) { // Verificação para não adicionar ponteiros nulos
            LEs.incluir(pE);
        }
    }

    // Percorre a lista e chama o método 'update' de cada entidade.
    void ListaEntidades::atualizar(float deltaTime) {
        // Usa o método getPrimeiro() da Lista para começar a iteração
        auto* pAux = LEs.getPrimeiro(); 
        while (pAux != nullptr) {
            // Pega a informação (a Entidade*) do elemento atual
            Entidade* pEntidade = pAux->getInfo();
            if (pEntidade) {
                pEntidade->update(deltaTime);
            }
            // Avança para o próximo elemento da lista
            pAux = pAux->getProximo();
        }
    }

    // Percorre a lista e chama o método 'render' de cada entidade.
    void ListaEntidades::render(sf::RenderWindow& window) {
        auto* pAux = LEs.getPrimeiro();
        while (pAux != nullptr) {
            Entidade* pEntidade = pAux->getInfo();
            if (pEntidade) {
                pEntidade->render(window);
            }
            pAux = pAux->getProximo();
        }
    }

    // Deleta todas as entidades e depois limpa os nós da lista
    void ListaEntidades::limpar() {
        auto* pAux = LEs.getPrimeiro();
        while (pAux != nullptr) {
            Entidade* pEntidade = pAux->getInfo();
            if (pEntidade) {
                delete pEntidade; // Deleta a entidade
            }
            pAux = pAux->getProximo();
        }
        LEs.limpar(); // Deleta os nós da lista (os 'Elementos')
    }
}