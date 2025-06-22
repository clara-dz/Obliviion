#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

namespace Obstaculos {

    class Plataforma : public Obstaculo {
    private:
        sf::Sprite cantoEsquerdo; // Sprite para o canto esquerdo da plataforma
        sf::Sprite cantoDireito;  // Sprite para o canto direito da plataforma
        sf::Sprite meio;          // Sprite para a parte do meio da plataforma
        std::vector<sf::Sprite> tiles; // Vetor para armazenar os tiles da plataforma
        float x, y;

        int altura; // Atributo específico, pode ser usado para algo no futuro

    public:
        Plataforma(const sf::Texture& leftTex, const sf::Texture& middleTex,
                   const sf::Texture& rightTex, float startX, float startY, int length);
        ~Plataforma();

        void desenhar(sf::RenderWindow& window);
        const std::vector<sf::FloatRect> getBounds() const;
        void afetar(Jogador& jogador) override {};

        void executar(float deltaTime) override;
        void salvar() override {};
        void obstaculizar(Jogador*p); //ainda n sei para que serve
    };

}