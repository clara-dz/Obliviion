#pragma once

#include "Lista.h"
#include "Entidade.h"

// Forward-declare para evitar incluir o header completo da SFML aqui
namespace sf {
    class RenderWindow;
}

namespace Listas {

    class ListaEntidades {
    private:
        Lista<Entidade> LEs;

    public:
        ListaEntidades();
        ~ListaEntidades();

        void incluir(Entidade* pE);
        void atualizar(float deltaTime);
        void renderizar(sf::RenderWindow& window);        
        void limpar();

        Lista<Entidade>& getLista() {
            return LEs;
        }
    };
}