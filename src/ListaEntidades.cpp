#include "ListaEntidades.h"
#include "Entidade.h"
#include <SFML/Graphics.hpp>

namespace Listas {

    void ListaEntidades::incluir(Entidades::Entidade* pE) {
        if (pE != nullptr) {
            LEs.incluir(pE);
        }
    }

    void ListaEntidades::atualizar(float deltaTime) {
        for (auto pEnt : LEs) {
            if (pEnt != nullptr) {
                pEnt->executar(deltaTime);
            }
        }
    }

    void ListaEntidades::renderizar(sf::RenderWindow& window) {
        for (auto pEnt : LEs) {
            if (pEnt != nullptr) {
                pEnt->renderizar(window);
            }
        }
    }

    void ListaEntidades::limpar() {
        LEs.limpar();
    }

}
