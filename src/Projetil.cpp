#include "Projetil.h"
#include "Jogador.h" 
#include <iostream>

// Um projétil começa sua vida 'inativo'.
Projetil::Projetil(const sf::Texture& texture) : 
    Entidade(), 
    velocidade(0.f, 0.f), 
    ativo(false) 
{
    setSprite(texture); // Configura a textura do projétil
    isVisible = false;  // Começa invisível
}

Projetil::~Projetil() {}

void Projetil::disparar(sf::Vector2f pos, sf::Vector2f vel) {
    sprite.setPosition(pos);
    velocidade = vel;
    ativo = true;
    isVisible = true; // Torna-se visível ao ser disparado
}

bool Projetil::estaAtivo() const {
    return ativo;
}

void Projetil::update(float deltaTime) {
    // Se o projétil não estiver ativo, não faz nada.
    if (!ativo) {
        return;
    }

    // Move o projétil com base na sua velocidade
    sprite.move(velocidade * deltaTime);

    // Lógica para desativar o projétil se ele sair da tela
    // (Ajuste os valores conforme o tamanho da sua fase)
    sf::Vector2f pos = sprite.getPosition();
    if (pos.y > 600 || pos.y < 0 || pos.x > 800 || pos.x < 0) {
        ativo = false;
        isVisible = false;
    }
}

void Projetil::handleCollision(Entidade& other) {
    // Se o projétil não estiver ativo, não pode colidir.
    if (!ativo) {
        return;
    }

    // Tenta converter 'other' para um ponteiro de Jogador.
    // Se a conversão for bem-sucedida, significa que colidimos com um jogador.
    Jogador* pJogador = dynamic_cast<Jogador*>(&other);
    
    if (pJogador != nullptr) {
        // Se colidiu com um jogador, o projétil se desativa.
        // A lógica de dano ficaria no handleCollision do próprio jogador.
        ativo = false;
        isVisible = false;
        std::cout << "Projetil atingiu o jogador!" << std::endl;
    }

}

void Projetil::render(sf::RenderWindow& window) {
    // Só desenha o projétil na tela se ele estiver ativo.
    if (ativo) {
        Entidade::render(window); // Chama o método render da classe base
    }
}