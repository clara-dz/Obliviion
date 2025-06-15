// Lista.h
#pragma once

#include <iostream>

namespace Listas {

    template <typename TL>
    class Lista {
    private:
        // Classe aninhada (nested class) que representa cada elo da lista.
        template <typename TE>
        class Elemento {
        private:
            Elemento<TE>* pProx; // Ponteiro para o próximo elemento
            TE* pinfo;           // Ponteiro para a informação armazenada

        public:
            // Construtor: inicializa os ponteiros como nulos.
            Elemento() : pProx(nullptr), pinfo(nullptr) {}

            // Destrutor: não faz nada, a memória da informação (pinfo)
            // será gerenciada externamente.
            ~Elemento() {}

            // Define a informação que este elemento irá guardar.
            void setInfo(TE* p) {
                pinfo = p;
            }

            // Define qual será o próximo elemento na lista.
            void setProx(Elemento<TE>* pE) {
                pProx = pE;
            }
            
            // Retorna o ponteiro para a informação.
            TE* getInfo() const {
                return pinfo;
            }

            // Retorna o ponteiro para o próximo elemento.
            Elemento<TE>* getProximo() const {
                return pProx;
            }
        };

        Elemento<TL>* pPrimeiro; // Ponteiro para o primeiro elemento da lista
        Elemento<TL>* pUltimo;   // Ponteiro para o último elemento da lista

    public:
        // Construtor da Lista: inicializa a lista como vazia.
        Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

        // Destrutor da Lista: chama a função para limpar toda a memória alocada.
        ~Lista() {
            limpar();
        }

        // Inclui um novo item no final da lista.
        void incluir(TL* p) {
            Elemento<TL>* novoElemento = new Elemento<TL>();
            novoElemento->setInfo(p);

            if (pPrimeiro == nullptr) { // Se a lista estiver vazia
                pPrimeiro = novoElemento;
                pUltimo = novoElemento;
            } else { // Se a lista já tiver elementos
                pUltimo->setProx(novoElemento);
                pUltimo = novoElemento;
            }
        }

        // Remove todos os elementos da lista, liberando a memória.
        void limpar() {
            Elemento<TL>* pAux = pPrimeiro;
            while (pAux != nullptr) {
                pPrimeiro = pPrimeiro->getProximo();
                delete pAux;
                pAux = pPrimeiro;
            }
            pPrimeiro = nullptr;
            pUltimo = nullptr;
        }

        // Retorna o primeiro elemento para permitir a iteração.
        Elemento<TL>* getPrimeiro() const {
            return pPrimeiro;
        }
    };
}