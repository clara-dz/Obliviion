#pragma once

#include "Jogador.h"
#include <vector>
#include <set>
#include "Floor.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include <list>
#include "Projetil.h"
#include "Entidade.h"
#include "Plataforma.h"
#include "Lista.h"


class GerenciadorColisoes {
    private:
        static GerenciadorColisoes* instancia;
        GerenciadorColisoes() : pJog1(nullptr), pJog2(nullptr) {}
    
        Jogador* pJog1;
        Jogador* pJog2;
        std::vector<Inimigo*> listaInimigos;
        std::vector<Entidades::Obstaculos::Obstaculo*> listaObstaculos;
        std::set<Entidades::Projetil*> listaProjeteis;

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

        std::set <Entidades::Projetil*>& getListaProjeteis() {
            return listaProjeteis;
        }
        void resetar();
        void incluirInimigos(Inimigo* pI);
        void incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
        void incluirProjetil(Entidades::Projetil* pJ);

        
        void checarColisoes(Personagem& Personagem, const Floor& floor, const std::vector<Entidades::Obstaculos::Plataforma>& plataformas);
        void checarColisaoEntrePersonagens(Personagem& p1, Personagem& p2);
        void tratarColisaoJogsInimigs(Jogador& jogador, Inimigo& inimigo);
        
        void renderizarProjeteis(sf::RenderWindow& window);
        void atualizarProjeteis(float dt); 
        void tratarColisaoProjeteis();
        void removerProjeteisInativos();
        void removerInimigos();

        void reset();
        
        void tratarColisaoJogsObstacs();
        int getListaObstaculosSize() const {
            return listaObstaculos.size();
        }
        // void executar();
        void checarQuedaMortal(Personagem* personagem);

    private:
        const bool verificarColisao(Personagem& p1, Personagem& p2);
        // void tratarColisaoJogsProjeteis(); //tratarColisaoProjeteis includes that
};

