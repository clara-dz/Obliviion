#include "GerenciadorGrafico.h"
#include <iostream>

// Inicializa o ponteiro da instância estática como nulo.
// Isso é feito fora da classe.
Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::instancia = nullptr;

namespace Gerenciadores {

    // Método que controla o acesso à instância Singleton.
    GerenciadorGrafico* GerenciadorGrafico::getInstance() {
        // Se a instância ainda não existe, crie-a.
        if (instancia == nullptr) {
            instancia = new GerenciadorGrafico();
        }
        // Retorna o ponteiro para a única instância.
        return instancia;
    }

    // O construtor agora é responsável por criar a janela.
    GerenciadorGrafico::GerenciadorGrafico() {
        // Pega a lógica que estava na classe Game
        window = new sf::RenderWindow(sf::VideoMode(800, 600), "Obliviion");
        window->setFramerateLimit(144);
    }

    GerenciadorGrafico::~GerenciadorGrafico() {
        delete window;
        // Não deletamos a 'instancia' aqui para evitar problemas de ordem de destruição.
        // O sistema operacional limpará a memória quando o programa fechar.
    }

    sf::RenderWindow* GerenciadorGrafico::getJanela() {
        return window;
    }

    void GerenciadorGrafico::limparTela() {
        window->clear();
    }

    void GerenciadorGrafico::mostrarTela() {
        window->display();
    }

    bool GerenciadorGrafico::janelaEstaAberta() const {
        return window->isOpen();
    }

    void GerenciadorGrafico::fecharJanela() {
        window->close();
    }

} 