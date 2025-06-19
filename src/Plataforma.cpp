#include "Plataforma.h"
#include <iostream>

namespace Obstaculos {

    Plataforma::Plataforma(const sf::Texture& leftTex, const sf::Texture& middleTex,
                           const sf::Texture& rightTex, float startX, float startY, int length)
        : x(startX), y(startY), altura(0) {

        cantoEsquerdo.setTexture(leftTex);
        cantoEsquerdo.setPosition(x, y);
        tiles.push_back(cantoEsquerdo);

        meio.setTexture(middleTex); // store for reuse (not drawn directly)
        for (int i = 0; i < length; ++i) {
            sf::Sprite mid(middleTex);
            mid.setPosition(x + (i + 1) * middleTex.getSize().x, y);
            tiles.push_back(mid);
        }

        cantoDireito.setTexture(rightTex);
        cantoDireito.setPosition(x + (length + 1) * middleTex.getSize().x, y);
        tiles.push_back(cantoDireito);

        // Configura a hitbox principal com base no tamanho total
        hitbox.setSize(sf::Vector2f((length + 2) * middleTex.getSize().x, middleTex.getSize().y));
        hitbox.setPosition(x, y);
    }

    Plataforma::~Plataforma() {}

    void Plataforma::desenhar(sf::RenderWindow& window) {
        for (auto& tile : tiles)
            window.draw(tile);
    }

    const std::vector<sf::FloatRect> Plataforma::getBounds() const {
        std::vector<sf::FloatRect> bounds;
        for (const auto& tile : tiles)
            bounds.push_back(tile.getGlobalBounds());
        return bounds;
    }

    void Plataforma::executar(float deltaTime) {
        // Plataformas são estáticas por padrão, mas podem ter lógica futuramente
    }

    void Plataforma::salva() {
        // Se for salvar em arquivo ou algo do tipo, coloque aqui
    }

    void Plataforma::obstaculizar(Jogador* p) {
        // Sem função clara no momento
    }

}
