#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TelaGameOver {
private:
    std::string nomeJogador;
    sf::Font fonte;
    sf::Text inputText;
    bool terminou = false;

public:
    TelaGameOver() {
        if (!fonte.loadFromFile("../assets/fonts/arial.ttf")) {
            // handle error
        }
        inputText.setFont(fonte);
        inputText.setCharacterSize(32);
        inputText.setFillColor(sf::Color::White);
        inputText.setPosition(200.f, 300.f);
    }

    void processarEvento(const sf::Event& event) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b' && !nomeJogador.empty()) {
                nomeJogador.pop_back();
            } else if (event.text.unicode == '\r' || event.text.unicode == '\n') {
                terminou = true; // Enter pressed
            } else if (event.text.unicode < 128 && isprint(event.text.unicode)) {
                nomeJogador += static_cast<char>(event.text.unicode);
            }
        }
    }

    void atualizar() {
        inputText.setString("Digite seu nome: " + nomeJogador);
    }

    void desenhar(sf::RenderWindow& window) {
        window.clear();
        window.draw(inputText);
        window.display();
    }

    bool terminouEntrada() const { return terminou; }

    std::string getNomeJogador() const { return nomeJogador; }
};
