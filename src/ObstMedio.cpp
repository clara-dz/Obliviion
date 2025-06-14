#include "Obst_medio.h"
#include "Personagem.h"
#include <iostream>

namespace Obstaculos {

    // Construtor do Obstáculo Médio
    Obst_medio::Obst_medio(const sf::Texture& texture, int x, int y) : 
        Obstaculo() // Chama o construtor da classe base
    {
        // Define as propriedades específicas deste tipo de obstáculo
        danoso = false; // Obstáculos médios, por padrão, não causam dano
        setSprite(texture);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));

        // Inicializa seu atributo específico
        largura = getBounds().width;
    }

    Obst_medio::~Obst_medio() {}

    void Obst_medio::update(float deltaTime) {
    }

    // A principal lógica está no tratamento de colisão.
    void Obst_medio::handleCollision(Entidade& other) {
        // Primeiro, tentamos converter a 'outra' entidade para um Personagem.
        // Se a conversão falhar (retornar nullptr), significa que não é um Jogador ou Inimigo,
        // então não fazemos nada.
        Personagem* pPersonagem = dynamic_cast<Personagem*>(&other);

        if (pPersonagem != nullptr) {
            // A lógica aqui é idêntica à da Plataforma.
            // Queremos que o Personagem pare em cima do obstáculo se estiver caindo.
            sf::FloatRect boundsPersonagem = pPersonagem->getBounds();
            sf::FloatRect boundsObstaculo = this->getBounds();

            // Condição 1: O personagem está em movimento de queda (velocidade Y para baixo é positiva).
            // Condição 2: A parte de baixo do personagem está logo acima da parte de cima do obstáculo.
            // A verificação 'boundsObstaculo.top + 20.f' cria uma pequena "folga" para garantir a detecção.
            if (pPersonagem->getVelocityY() > 0.f &&
                (boundsPersonagem.top + boundsPersonagem.height) < (boundsObstaculo.top + 20.f) )
            {
                // Calcula o quanto o personagem "entrou" no obstáculo
                float overlap = (boundsPersonagem.top + boundsPersonagem.height) - boundsObstaculo.top;
                
                // Corrige a posição do personagem, movendo-o para cima
                pPersonagem->move({0.f, -overlap});
                
                // Informa ao personagem que ele parou de cair e agora está no chão
                pPersonagem->stopFalling();
            }
        }
    }

    // Lógica futura para salvar o estado deste obstáculo.
    void Obst_medio::salva() {
        std::cout << "Salvando estado do Obst_medio..." << std::endl;
    }

}