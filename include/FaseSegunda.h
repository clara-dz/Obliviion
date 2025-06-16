#pragma once
#include "Fase.h"
#include "ListaEntidades.h"
#include "Chefao.h"
#include "ObstaculoDificil.h"
#include "ObstaculoMedio.h"
#include "InimigoMedio.h"

//Fase InfernoDeDante

// Forward declarations para evitar includes pesados no .h
class Jogador;
class Chefao;

class FaseSegunda : public Fase {
private:
    const int maxChefoes = 1; //Um chefao na fase apenas

    // Usamos ListaEntidades para gerenciar a memória e os updates/renders
    //Além disso, a classe Lista, prevista no diagram, precisa ser usada
    //mas acredito que seja melhor usar as listas para salvar o sistema de pontuacao e dano
    Listas::ListaEntidades listaObstaculos; // obstaculo Medio e Dificil
    Listas::ListaEntidades listaInimigos; // inimigo medio e chefao

    // A fase precisa de uma referência ao jogador para passá-lo para os gerenciadores
    Jogador* pJogador1;
    Jogador* pJogador2; // Pode ser nullptr para single player

    // Texturas específicas desta fase
    sf::Texture texturaChefao;
    sf::Texture texturaProjetil;
    sf::Texture texturaObsDificil;
    sf::Texture texturaObsMedio;
    sf::Texture texturaPlataforma;
    sf::Texture texturaJogador; // Supondo que a fase crie o jogador

    // Métodos privados para organizar a criação da fase
    void criarJogadores();
    void criarChefao();
    void criarObsMedio();
    void criarObsDificil();
    void criarPlataformas();


public:
    FaseSegunda(const std::string& name = "Inferno de Dante");
    ~FaseSegunda();

    // Implementação dos métodos virtuais puros da classe Fase
    void loadLevel() override;
    void executar(float deltaTime) override;
    void renderizar(sf::RenderWindow& window) override;
};