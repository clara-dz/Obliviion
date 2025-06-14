#include "InimigoMedio.h"
#include "Jogador.h" 
#include <iostream>

InimigoMedio::InimigoMedio(const sf::Texture& texture, int x, int y, int speed) :
    Inimigo(x, y, speed), // Chama o construtor da classe Inimigo
    tamanho(50)           // Exemplo de valor inicial
{
    setSprite(texture);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    nivel_maldade = 2; // Inimigo médio tem maldade nível 2 (exemplo)
    startFalling();    // Começa aplicando a gravidade
}

InimigoMedio::~InimigoMedio() {}

void InimigoMedio::update(float deltaTime) {
    // Lógica de movimento simples: patrulhar de um lado para o outro (exemplo)
    // Para isso, precisaríamos de mais atributos (direção, limites de patrulha).
    // Por enquanto, vamos deixá-lo parado, apenas sujeito à gravidade.
    
    applyGravity(deltaTime);
    // Para um movimento simples, poderíamos fazer: sprite.move(-speed * deltaTime, 0.f);

    // Atualiza a posição do sprite com base na física (gravidade)
    sprite.move(0.f, velocityY);
}

void InimigoMedio::handleCollision(Entidade& other) {
    // Lógica de colisão. Ex: se colidir com um obstáculo, inverte a direção.
    // Por enquanto, podemos deixar vazio.
}

void InimigoMedio::danificar(Jogador* pJogador) {
    // Lógica de ataque. Ex: Causa dano ao jogador.
    // A implementação real chamaria um método pJogador->receberDano(10);
    std::cout << "Inimigo Medio ataca o jogador!" << std::endl;
}

void InimigoMedio::salva() {
    // Lógica para salvar o estado deste inimigo.
    // Por enquanto, podemos deixar vazio.
    std::cout << "Salvando estado do InimigoMedio..." << std::endl;
}