#pragma once
#include "Fase.h"
#include "ListaEntidades.h" 

// Forward declarations para evitar includes pesados no .h
class Jogador;
class Chefao;

class FaseSegunda : public Fase {
private:
    // Usamos ListaEntidades para gerenciar a memória e os updates/renders
    Listas::ListaEntidades listaObstaculos;
    Listas::ListaEntidades listaInimigos;

    // A fase precisa de uma referência ao jogador para passá-lo para os gerenciadores
    Jogador* pJogador1;
    Jogador* pJogador2; // Pode ser nullptr para single player

    // Texturas específicas desta fase
    sf::Texture texturaChefao;
    sf::Texture texturaProjetil;
    sf::Texture texturaObstaculoDificil;
    sf::Texture texturaPlataforma;
    sf::Texture texturaJogador; // Supondo que a fase crie o jogador

    // Métodos privados para organizar a criação do nível
    void criarJogadores();
    void criarChefao();
    void criarObstaculos();
    void criarPlataformas();

public:
    FaseSegunda(const std::string& name = "Fase Segunda");
    ~FaseSegunda();

    // Implementação dos métodos virtuais puros da classe Fase
    void loadLevel() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};