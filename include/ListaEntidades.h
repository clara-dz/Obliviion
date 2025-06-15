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

        // Adiciona uma nova entidade (ponteiro) à lista
        void incluir(Entidade* pE);

        // Funções principais que iteram sobre a lista
        void atualizar(float deltaTime);
        void render(sf::RenderWindow& window);
        
        // Limpa a lista, deletando todas as entidades
        void limpar();
    };
}