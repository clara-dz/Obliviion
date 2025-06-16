#pragma once

#include "Inimigo.h"
#include "Projetil.h" // Incluímos o projétil que ele usará
#include <vector>
#include <SFML/System/Clock.hpp>

class Chefao : public Inimigo { // Nome: EmoBoss
private:
    short int forca;
    int vida;

    // Pool de projéteis que o chefe pode disparar
    std::vector<Projetil*> projeteis;

    // Controle do tempo de ataque
    sf::Clock relogioAtaque;
    float cooldownAtaque;

    // Método privado para encapsular a lógica de ataque
    void atacar();

public:
    // O construtor precisa de duas texturas: uma para o chefe e outra para seus projéteis
    Chefao(const sf::Texture& texture, const sf::Texture& textura_projetil, int x = 0, int y = 0);
    ~Chefao();

    // Implementação dos métodos virtuais herdados
    void executar(float deltaTime) override;
    void handleCollision(Entidade& other) override;
    void danificar(Jogador* pJogador);
    void salva();

    // Sobrescrevemos o render para também desenhar os projéteis
    void render(sf::RenderWindow& window) override;
};