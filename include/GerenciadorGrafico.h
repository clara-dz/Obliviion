#pragma once
#include <SFML/Graphics.hpp>

// Ente para evitar incluir o header e criar dependências circulares
class Ente;

namespace Gerenciadores {

    class GerenciadorGrafico {
        private:
            // Ponteiro para a janela principal do jogo.
            sf::RenderWindow* window;

            // A única instância da classe 
            static GerenciadorGrafico* instancia;

            // Construtor privado para garantir que apenas um objeto seja criado.
            GerenciadorGrafico();

        public:
            ~GerenciadorGrafico();

            // Método de acesso estático para obter a instância única //Sugestão do ChatGPT
            static GerenciadorGrafico* getInstance();

            GerenciadorGrafico(const GerenciadorGrafico&) = delete;
            GerenciadorGrafico& operator=(const GerenciadorGrafico&) = delete;

            // Retorna um ponteiro para a janela, para que outros objetos possam desenhar nela 
            sf::RenderWindow* getJanela();

            // Funções de controle da janela
            void limparTela();
            void mostrarTela();
            bool janelaEstaAberta() const;
            void fecharJanela();
            void desenharEnte(Ente* pE);
        };

} //Essa classe foi criada com base no diagrama UML disponibilizado pelo professor e códigos sugeridos pelo ChatGPT