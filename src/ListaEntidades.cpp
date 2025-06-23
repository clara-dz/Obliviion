#include "ListaEntidades.h"
#include "Entidade.h"
#include <SFML/Graphics.hpp>

namespace Listas {

    void ListaEntidades::incluir(Entidades::Entidade* pE) {
        if (pE != nullptr) {
            LEs.inserir(pE);
        }
    }

    void ListaEntidades::atualizar(float deltaTime) {
        for (int i = 0; i < LEs.getTamanho(); ++i) {
            Entidades::Entidade* pEnt = LEs[i];
            if (pEnt != nullptr) {
                pEnt->atualizar(deltaTime);
            }
        }
    }

    void ListaEntidades::renderizar(sf::RenderWindow& window) {
        for (int i = 0; i < LEs.getTamanho(); ++i) {
            Entidades::Entidade* pEnt = LEs[i];
            if (pEnt != nullptr) {
                pEnt->renderizar(window);
            }
        }
    }

    void ListaEntidades::limpar() {
        LEs.limpar();  // Assuming this deletes or clears the list content
    }

}
