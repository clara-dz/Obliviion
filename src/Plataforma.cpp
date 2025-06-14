#include "Plataforma.h"
#include "Personagem.h" 

namespace Obstaculos {

    Plataforma::Plataforma(const sf::Texture& texture, int x, int y) : Obstaculo() {
        danoso = false; // Plataformas não causam dano
        setSprite(texture);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    }

    Plataforma::~Plataforma() {}

    void Plataforma::update(float deltaTime) {
        // Plataformas são estáticas, então o update não faz nada.
        // No futuro, poderíamos ter plataformas móveis implementando lógica aqui.
    }

    void Plataforma::handleCollision(Entidade& other) {
        // Tenta converter 'other' para Personagem para acessar a física
        Personagem* pPersonagem = dynamic_cast<Personagem*>(&other);
        if (pPersonagem) {
            // Lógica para o personagem ficar em cima da plataforma
            // Se o personagem está caindo (velocidade Y > 0) e a parte de baixo
            // dele colide com a parte de cima da plataforma, paramos a queda.
            sf::FloatRect boundsPersonagem = pPersonagem->getBounds();
            sf::FloatRect boundsPlataforma = this->getBounds();

            if (pPersonagem->getVelocityY() > 0.f &&
                (boundsPersonagem.top + boundsPersonagem.height) < (boundsPlataforma.top + 20.f) )
            {
                float overlap = (boundsPersonagem.top + boundsPersonagem.height) - boundsPlataforma.top;
                pPersonagem->move({0.f, -overlap}); // Corrige a posição
                pPersonagem->stopFalling();
            }
        }
    }

    void Plataforma::salva() { /* Lógica de save futura */ }

}