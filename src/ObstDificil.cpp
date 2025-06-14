#include "Obst_Dificil.h"
#include "Jogador.h"

namespace Obstaculos {

    Obst_Dificil::Obst_Dificil(const sf::Texture& texture, int x, int y, short int dano) : Obstaculo() {
        danoso = true; // Este obstáculo CAUSA dano
        danosidade = dano;
        setSprite(texture);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    }

    Obst_Dificil::~Obst_Dificil() {}

    void Obst_Dificil::update(float deltaTime) {
        // Pode ser estático ou ter um movimento/animação (ex: espinhos que sobem e descem)
    }

    void Obst_Dificil::handleCollision(Entidade& other) {
        // Se este obstáculo é danoso, ele tenta causar dano ao jogador
        if (danoso) {
            Jogador* pJogador = dynamic_cast<Jogador*>(&other);
            if (pJogador) {
                // Aqui chamaríamos um método para o jogador tomar dano.
                // Como ainda não temos, vamos usar um cout.
                // pJogador->receberDano(danosidade);
                std::cout << "Jogador tomou " << danosidade << " de dano do obstaculo!" << std::endl;
            }
        }
    }

    void Obst_Dificil::salva() { /* Lógica de save futura */ }
}