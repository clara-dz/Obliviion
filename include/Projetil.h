#pragma once

#include "Entidade.h"

class Projetil : public Entidade {
protected:
    sf::Vector2f velocidade;
    bool ativo;

public:
    // O construtor precisa de uma textura para o sprite do projétil
    Projetil(const sf::Texture& texture);
    ~Projetil();

    // Ativa o projétil, definindo sua posição e velocidade iniciais
    void disparar(sf::Vector2f pos, sf::Vector2f vel);

    // Verifica se o projétil está atualmente em movimento
    bool estaAtivo() const;

    // Métodos virtuais herdados de Entidade que PRECISAM ser implementados
    void executar(float deltaTime) override;
    void handleCollision(Entidade& other) override;
    
    // Vamos sobrescrever o render para desenhar apenas se estiver ativo
    void render(sf::RenderWindow& window) override;
};