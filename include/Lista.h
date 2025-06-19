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
            Elemento() : pProx(nullptr), pinfo(nullptr) {}
            ~Elemento() {}

            void setInfo(TE* p) { pinfo = p; }
            void setProx(Elemento<TE>* pE) { pProx = pE; }
            TE* getInfo() const { return pinfo; }
            Elemento<TE>* getProximo() const { return pProx; }
        };

        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;

    public:
        Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

        ~Lista() {
            limpar();
        }

        void incluir(TL* p) {
            Elemento<TL>* novoElemento = new Elemento<TL>();
            novoElemento->setInfo(p);

            if (pPrimeiro == nullptr) {
                pPrimeiro = novoElemento;
                pUltimo = novoElemento;
            } else {
                pUltimo->setProx(novoElemento);
                pUltimo = novoElemento;
            }
        }

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

        Elemento<TL>* getPrimeiro() const {
            return pPrimeiro;
        }

        // ================================
        // Custom Iterator Implementation
        // ================================
        class Iterator {
        private:
            Elemento<TL>* atual;

        public:
            Iterator(Elemento<TL>* p) : atual(p) {}

            TL* operator*() const {
                return atual->getInfo();
            }

            Iterator& operator++() {
                if (atual)
                    atual = atual->getProximo();
                return *this;
            }

            bool operator!=(const Iterator& outro) const {
                return atual != outro.atual;
            }
        };

        Iterator begin() const {
            return Iterator(pPrimeiro);
        }

        Iterator end() const {
            return Iterator(nullptr);
        }
    };

}
