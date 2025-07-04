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
        Lista<Entidades::Entidade> LEs;

    public:
        ListaEntidades() = default;
        ~ListaEntidades() = default;

        void incluir(Entidades::Entidade* pE);
        void atualizar(float deltaTime);
        int getTamanho() const {
            return LEs.getTamanho();
        }
        void renderizar(sf::RenderWindow& window);        
        void limpar();

        Lista<Entidades::Entidade>& getLista() {
            return LEs;
        }
    };
}