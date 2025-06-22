#pragma once

#include "Inimigo.h"
#include "Projetil.h" // Incluímos o projétil que ele usará
#include <vector>
#include <SFML/System/Clock.hpp>

class EmoBoss : public Inimigo { // Nome: EmoBoss
private:
    short int forca;
    int vida;

    // Pool de projéteis que o chefe pode disparar
    std::vector<Projetil*> projeteis;

    // Controle do tempo de ataque
    sf::Clock relogioAtaque;
    float cooldownAtaque;

public:
    // O construtor precisa de duas texturas: uma para o chefe e outra para seus projéteis
    EmoBoss(const sf::Texture& texture, const sf::Texture& textura_projetil, int x = 0, int y = 0);
    ~EmoBoss();

    void executar(float deltaTime) override;
    // void danificar(Jogador* pJogador) override {};

    void salva();

    // Sobrescrevemos o renderizar para também desenhar os projéteis
    void renderizar(sf::RenderWindow& window) override;
};