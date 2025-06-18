#pragma once
#include "Inimigo.h"

class InimigoMedio : public Inimigo { // Nome: EmoBoy
private:
    int tamanho;

public:
    InimigoMedio(const sf::Texture& texture, int x = 0, int y = 0, int speed = 0);
    ~InimigoMedio();

    // Implementação dos métodos virtuais puros herdados de Inimigo e Entidade
    void executar(float deltaTime) override;
    void handleCollision(Entidade& other) override;
    // void danificar(Jogador* pJogador) override {};
    // void salva() override;
};