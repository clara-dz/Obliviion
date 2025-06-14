#include "Chefao.h"
#include "Jogador.h"
#include <iostream>

Chefao::Chefao(const sf::Texture& texture, const sf::Texture& textura_projetil, int x, int y) :
    Inimigo(x, y, 15), // Chama o construtor de Inimigo com uma velocidade baixa
    forca(25),
    vida(500),
    cooldownAtaque(2.5f) // Ataca a cada 2.5 segundos
{
    setSprite(texture);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    nivel_maldade = 10;

    // Cria o pool de projéteis para o chefe. Eles começam inativos.
    for (int i = 0; i < 10; ++i) {
        projeteis.push_back(new Projetil(textura_projetil));
    }
}

// O destrutor precisa limpar a memória alocada para os projéteis
Chefao::~Chefao() {
    for (Projetil* p : projeteis) {
        if (p) {
            delete p;
        }
    }
    projeteis.clear();
}

void Chefao::update(float deltaTime) {
    // Lógica de movimento do Chefão (pode ser mais complexa no futuro)
    // Ex: mover-se em direção ao jogador mais próximo.
    // Por enquanto, ele fica parado, sujeito à gravidade.
    applyGravity(deltaTime);
    sprite.move(0.f, velocityY);

    // Chama o método de ataque
    atacar();

    // Atualiza todos os projéteis (ativos ou não)
    for (Projetil* p : projeteis) {
        p->update(deltaTime);
    }
}

void Chefao::atacar() {
    // Se o tempo desde o último ataque for maior que o cooldown...
    if (relogioAtaque.getElapsedTime().asSeconds() > cooldownAtaque) {
        // ...procura um projétil inativo para disparar.
        for (Projetil* p : projeteis) {
            if (!p->estaAtivo()) {
                // Posição de onde o projétil sai (centro do chefe, por exemplo)
                sf::Vector2f pos_disparo = sprite.getPosition();
                pos_disparo.x += getBounds().width / 2;
                
                // Dispara em uma direção (ex: para a esquerda)
                p->disparar(pos_disparo, sf::Vector2f(-150.f, 0.f));
                
                // Reinicia o relógio
                relogioAtaque.restart();
                
                // Sai do loop pois já disparamos um projétil
                break; 
            }
        }
    }
}

void Chefao::render(sf::RenderWindow& window) {
    // Desenha o sprite do próprio chefe
    Inimigo::render(window);

    // Desenha todos os projéteis ativos
    for (Projetil* p : projeteis) {
        p->render(window);
    }
}

void Chefao::handleCollision(Entidade& other) {
    // Lógica de colisão. Ex: se um projétil do jogador o atinge, ele perde vida.
}

void Chefao::danificar(Jogador* pJogador) {
    // Lógica de ataque corpo-a-corpo, se houver.
    std::cout << "Chefao ataca o jogador com forca " << forca << "!" << std::endl;
}

void Chefao::salva() {
    // Lógica para salvar o estado do chefe.
}