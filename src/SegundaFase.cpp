#include "FaseSegunda.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "Chefao.h"
#include "Plataforma.h"
#include "Obst_Dificil.h"
#include <iostream>

FaseSegunda::FaseSegunda(const std::string& name) : 
    Fase(name), pJogador1(nullptr), pJogador2(nullptr)
{
    // Carrega todas as texturas necessárias para esta fase
    if (!texturaChefao.loadFromFile("../assets/images/chefao.png")) { /* erro */ }
    if (!texturaProjetil.loadFromFile("../assets/images/projetil.png")) { /* erro */ }
    if (!texturaObstaculoDificil.loadFromFile("../assets/images/espinhos.png")) { /* erro */ }
    if (!texturaPlataforma.loadFromFile("../assets/images/plataforma2.png")) { /* erro */ }
    if (!texturaJogador.loadFromFile("../assets/images/player.png")) { /* erro */ }

    // Carrega a textura de fundo da fase
    loadBackgroundTexture("../assets/images/background2.png");
}

FaseSegunda::~FaseSegunda() {
    // As ListaEntidades cuidarão de deletar os ponteiros,
    // então o destrutor pode ficar vazio.
}

// loadLevel orquestra a criação de todo o cenário
void FaseSegunda::loadLevel() {
    // Limpa as listas do gerenciador de colisões de qualquer fase anterior
    Gerenciadores::GerenciadorColisoes::getInstance()->limparListas();

    // Chama os métodos auxiliares para popular a fase
    criarJogadores();
    criarChefao();
    criarObstaculos();
    criarPlataformas();
    
    // Configura os jogadores no gerenciador de colisões
    Gerenciadores::GerenciadorColisoes::getInstance()->setJogadores(pJogador1, pJogador2);
}

// Lógica de atualização da fase a cada frame
void FaseSegunda::update(float deltaTime) {
    // Atualiza todas as entidades da fase
    if(pJogador1) pJogador1->update(deltaTime);
    if(pJogador2) pJogador2->update(deltaTime);
    listaInimigos.atualizar(deltaTime);
    listaObstaculos.atualizar(deltaTime);

    // Executa a detecção e tratamento de colisões
    Gerenciadores::GerenciadorColisoes::getInstance()->executar();
}

// Desenha todos os elementos da fase na tela
void FaseSegunda::render(sf::RenderWindow& window) {
    drawBackground(window); // Desenha o fundo
    
    // Manda as listas de entidades se desenharem
    listaObstaculos.render(window);
    listaInimigos.render(window);

    // Desenha os jogadores
    if(pJogador1) pJogador1->render(window);
    if(pJogador2) pJogador2->render(window);
}


void FaseSegunda::criarJogadores() {
    pJogador1 = new Jogador(texturaJogador);
    pJogador1->setPosition({100.f, 100.f});
    Gerenciadores::GerenciadorColisoes::getInstance()->incluirJogador(pJogador1);
    // Para um segundo jogador:
    // pJogador2 = new Jogador(texturaJogador);
    // pJogador2->setPosition({150.f, 100.f});
}

void FaseSegunda::criarChefao() {
    Chefao* pChefao = new Chefao(texturaChefao, texturaProjetil, 600, 350);
    listaInimigos.incluir(pChefao);
    Gerenciadores::GerenciadorColisoes::getInstance()->incluirInimigo(pChefao);
}

void FaseSegunda::criarObstaculos() {
    // Exemplo de obstáculos difíceis (espinhos) no chão
    for (int i = 0; i < 5; ++i) {
        Obstaculos::Obst_Dificil* pObs = new Obstaculos::Obst_Dificil(texturaObstaculoDificil, 200 + i * 64, 540);
        listaObstaculos.incluir(pObs);
        Gerenciadores::GerenciadorColisoes::getInstance()->incluirObstaculo(pObs);
    }
}

void FaseSegunda::criarPlataformas() {
    // Chão principal
    for (int i = 0; i < 25; ++i) {
        Obstaculos::Plataforma* pPlat = new Obstaculos::Plataforma(texturaPlataforma, i * 32, 580);
        listaObstaculos.incluir(pPlat);
        Gerenciadores::GerenciadorColisoes::getInstance()->incluirObstaculo(pPlat);
    }
    // Plataformas flutuantes
    Obstaculos::Plataforma* pPlat2 = new Obstaculos::Plataforma(texturaPlataforma, 400, 450);
    listaObstaculos.incluir(pPlat2);
    Gerenciadores::GerenciadorColisoes::getInstance()->incluirObstaculo(pPlat2);
}