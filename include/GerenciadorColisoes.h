#pragma once

#include <vector>
#include <list>
#include <set>

#include "Jogador.h"
#include "Floor.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "Entidade.h"
#include "Plataforma.h"


class GerenciadorColisoes {
    private:
        static GerenciadorColisoes* instancia;
        GerenciadorColisoes() : pJog1(nullptr), pJog2(nullptr) {}
    
        Jogador* pJog1;
        Jogador* pJog2;
        std::vector<Inimigo*>   listaInimigos;
        std::list<Obstaculo*>   listaObstaculos;
        std::set<Projetil*>     listaProjeteis;

    public:
        static GerenciadorColisoes* getInstancia() {
            if (!instancia) {
                instancia = new GerenciadorColisoes();
            }
            return instancia;
        }
        
        ~GerenciadorColisoes() {
            delete instancia;
            instancia = nullptr;
        }

        void setJogadores(Jogador* j1, Jogador* j2) {
            pJog1 = j1;
            pJog2 = j2;
        }

        void resetar();
        void incluirInimigos(Inimigo* pI);
        void incluirObstaculo(Obstaculo* pO);
        void incluirProjetil(Projetil* pJ);

        void renderizarProjeteis(sf::RenderWindow& window);
        
        void checarColisaoEntrePersonagens(Personagem& p1, Personagem& p2);
        void tratarColisaoJogsInimigs();
        void tratarColisaoProjeteis();
        void atualizarProjeteis(float dt);   // ✅ Declare method
        void removerProjeteisInativos();     // optional
        void checarColisoes(Personagem& Personagem, const Floor& floor, const std::vector<Obstaculos::Plataforma>& plataformas);
        
        // void executar();

    private:
        const bool verificarColisao(Personagem& p1, Personagem& p2);
        void tratarColisaoJogsObstacs();
        void tratarColisaoJogsProjeteis();
};

