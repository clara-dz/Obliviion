#include "InfernoDeDante.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>
#include "Floor.h"
#include <cstdlib>
#include <ctime>

#include "Config.h"

extern const unsigned int SCREEN_WIDTH;
extern const unsigned int FLOOR_HEIGHT;

using json = nlohmann::json;

//A implementação desta classe foi realizada com auxílio da AI ChatGPT

InfernoDeDante::InfernoDeDante(Jogador* j1, Jogador* j2)
    : Fase("Jardim do Eden", j1, j2),
      floor("../assets/images/tile1.png", SCREEN_WIDTH, FLOOR_HEIGHT)
    {}

InfernoDeDante::~InfernoDeDante() {}

void InfernoDeDante::criarInimFracos(){
    if (!EmoGirlTexture.loadFromFile("../assets/images/emogirl.png")) {
        std::cerr << "Error loading enemy texture!\n";
    }

    int n_randomico = 3 + (rand()%(maxInimigosFracos - 2));
    
    for (int i = 0; i < n_randomico; ++i) {
        // TODO: make moving left random
        EmoGirl enemy(750 - (70 * i), 200, 2, EmoGirlTexture);
        weakEnemies.push_back(enemy);
    }
}

void InfernoDeDante::criarInimMedios(){
    if (!emoBoyTexture.loadFromFile("../assets/images/emoboy.png")) {
        std::cerr << "Error loading emoBoy texture!\n";
    }

    for (int i = 0; i < maxIniminMedio; ++i) {
        EmoBoy emo(400 - (70 * i), 200, 20, emoBoyTexture);
        emo.setJogadores(pJog1, pJog2); // Set players for tracking
        mediumEnemies.push_back(emo);
    }
}

void InfernoDeDante::criarBosses(){
    if (!emoBossTexture.loadFromFile("../assets/images/emoboss.png")) {
        std::cerr << "Error loading boss texture!\n";
    }
    if (!emoBossProjTexture.loadFromFile("../assets/images/rock.png")) {
        std::cerr << "Error loading emoBoy texture!\n";
    }

    int n_randomico = 3 + (rand()%(maxBosses - 2));
    
    for (int i = 0; i < n_randomico; ++i) {
        EmoBoss boss(750 - (100 * i), 200, 20, emoBossTexture);
        boss.setJogadores(pJog1, pJog2); // Set players for tracking

        boss.setTexProjetil(&emoBossProjTexture);
        
        bosses.push_back(boss);
        std::cout << "Rendering boss: " << bosses.size() << std::endl;

    }
}

void InfernoDeDante::criarObsMedios(){
    if (!barrierTex.loadFromFile("../assets/images/stone_96x96.png")) {
        std::cerr << "Error loading platform textures!\n";
        exit(1);
    }

    obstaculos.push_back(new BarreiraDoLimbo(barrierTex, 400, 450));
}

void InfernoDeDante::criarPlataformas() {
    if (!plataformaEsqTex.loadFromFile("../assets/images/platLeft.png") ||
        !plataformaMeioTex.loadFromFile("../assets/images/platMid.png") ||
        !plataformaDirTex.loadFromFile("../assets/images/platRight.png")) {
        std::cerr << "Error loading platform textures!\n";
        exit(1);
    }

    //mapa para as posições das plataformas. Sugestão do ChatGPT
    std::ifstream file("../assets/maps/InfernoDeDante.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening level map file!\n";
        exit(1);
    }

    //Como o programa lê os arquivos
    std::string line;
    std::getline(file, line); // pula a primeira linha

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        float x, y;
        int length;
        char comma;
        ss >> x >> comma >> y >> comma >> length;
        plataformas.emplace_back(plataformaEsqTex, plataformaMeioTex, plataformaDirTex, x, y, length);
    }
}


void InfernoDeDante::loadLevel() {
    loadBackgroundTexture("../assets/images/background2.png");
    criarPlataformas();
    // criarObsMedios();
    criarInimFracos();
    criarInimMedios();
    criarBosses();

    // for (auto& o : obstaculos) {
    //     colisor->incluirObstaculo(o);
    // }
    
    colisor->setJogadores(pJog1, pJog2);
    
    for (auto& inimigo : weakEnemies) {
        colisor->incluirInimigos(&inimigo);
    }

    for (auto& inimigo : mediumEnemies) {
        colisor->incluirInimigos(&inimigo);
    }

    for (auto& inimigo : bosses) {
        colisor->incluirInimigos(&inimigo);
    }
}

void InfernoDeDante::executar(float deltaTime) {
    pJog1->executar(deltaTime);
    pJog2->executar(deltaTime);
    if (pJog1->isAlive)
        colisor->checarColisoes(*pJog1, floor, plataformas);

    if (pJog2->isAlive)
        colisor->checarColisoes(*pJog2, floor, plataformas);

    for (auto& enemy : weakEnemies) {
        if (!enemy.isAlive) continue; 
        
        enemy.executar(deltaTime);
        colisor->checarColisoes(enemy, floor, plataformas);
        
        if (pJog1->isAlive) {
            colisor->checarColisaoEntrePersonagens(*pJog1, enemy);
            colisor->tratarColisaoJogsInimigs(*pJog1, enemy);
        }
        if (pJog2->isAlive) {
            colisor->checarColisaoEntrePersonagens(*pJog2, enemy);
            colisor->tratarColisaoJogsInimigs(*pJog2, enemy);
        }
    }

        for (auto& enemy : mediumEnemies) {
        if (!enemy.isAlive) continue; 
        
        enemy.executar(deltaTime);
        colisor->checarColisoes(enemy, floor, plataformas);
        
        if (pJog1->isAlive) {
            colisor->checarColisaoEntrePersonagens(*pJog1, enemy);
            colisor->tratarColisaoJogsInimigs(*pJog1, enemy);
        }
        if (pJog2->isAlive) {
            colisor->checarColisaoEntrePersonagens(*pJog2, enemy);
            colisor->tratarColisaoJogsInimigs(*pJog2, enemy);
        }
    }

    for (auto& enemy : weakEnemies) {
        if (!enemy.isAlive) continue; 
        
        enemy.executar(deltaTime);
        colisor->checarColisoes(enemy, floor, plataformas);
        
        if (pJog1->isAlive) {
            colisor->checarColisaoEntrePersonagens(*pJog1, enemy);
            colisor->tratarColisaoJogsInimigs(*pJog1, enemy);
        }
        if (pJog2->isAlive) {
            colisor->checarColisaoEntrePersonagens(*pJog2, enemy);
            colisor->tratarColisaoJogsInimigs(*pJog2, enemy);
        }
    }

    for (auto& enemy : bosses) {
        if (!enemy.isAlive) continue; 
        
        enemy.executar(deltaTime);
        colisor->checarColisoes(enemy, floor, plataformas);
        
        if (pJog1->isAlive) {
            colisor->checarColisaoEntrePersonagens(*pJog1, enemy);
            colisor->tratarColisaoJogsInimigs(*pJog1, enemy);
        }
        if (pJog2->isAlive) {
            colisor->checarColisaoEntrePersonagens(*pJog2, enemy);
            colisor->tratarColisaoJogsInimigs(*pJog2, enemy);
        }
    }
    
    colisor->atualizarProjeteis(deltaTime);
    colisor->tratarColisaoProjeteis();
    colisor->removerProjeteisInativos();
    colisor->tratarColisaoJogsObstacs();


    if (todosInimigosMortos()) {
        std::cout << "Fase Concluída!\n";
        setCompleted(true);
    }
}

void InfernoDeDante::renderizar(sf::RenderWindow& window) {
    drawBackground(window);
    floor.renderizar(window);
    for (auto* obst : obstaculos) {
        if (obst) {
            obst->renderizar(window);
        }
    }

    if (pJog1->isAlive)
        pJog1->renderizar(window);
    
    if (pJog2->isAlive)
        pJog2->renderizar(window);

    for (auto& enemy : weakEnemies) {
        if (enemy.isAlive) // Only render alive enemies
        enemy.renderizar(window);
    }

    for (auto& enemy : mediumEnemies) {
        if (enemy.isAlive) // Only render alive enemies
        enemy.renderizar(window);
    }

    for (auto& enemy : bosses) {
        if (enemy.isAlive) // Only render alive enemies
        enemy.renderizar(window);
    }

    for (auto& plataforma : plataformas)
        plataforma.desenhar(window);

    colisor->renderizarProjeteis(window);
}

int InfernoDeDante::getPontuacaoTotalJogadores() const {
    return pJog1->getPontos();
}

bool InfernoDeDante::todosInimigosMortos() const {
    for (const auto& enemy : weakEnemies) {
        if (enemy.estaVivo()) return false;
    }
    return true;
}

bool InfernoDeDante::jogadoresMortos() const {
    return (!pJog1->estaVivo() && !pJog2->estaVivo());
}

//o código abaixo foi realizado com auxílio da AI Gemini

json InfernoDeDante::salvar() const {
    json data;
    
    data["levelName"] = levelName;
    data["player1"] = pJog1->salvar();
    data["player2"] = pJog2->salvar();

    data["weakEnemies"] = json::array();
    for (auto& enemy : weakEnemies) {
        if (enemy.isAlive) {
            data["weakEnemies"].push_back(enemy.salvar());
        }
    }

    data["mediumEnemies"] = json::array();
    for (auto& enemy : mediumEnemies) {
        if (enemy.isAlive) {
            data["mediumEnemies"].push_back(enemy.salvar());
        }
    }

    data["bosses"] = json::array(); // Assuming you have strong enemies to save
    for (auto& enemy : bosses) {
        if (enemy.isAlive) {
            data["bosses"].push_back(enemy.salvar());
        }
    }

    data["projectiles"] = json::array();
    for (const auto& proj : colisor->getListaProjeteis()) {
        data["projectiles"].push_back(proj->salvar());
    }

    return data;
}   