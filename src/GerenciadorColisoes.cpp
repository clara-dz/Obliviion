#include "GerenciadorColisoes.h"
#include <iostream>


GerenciadorColisoes* GerenciadorColisoes::instancia = nullptr;

void GerenciadorColisoes::resetar() {
    listaInimigos.clear();
    listaObstaculos.clear();
    listaProjeteis.clear();
    pJog1 = nullptr;
    pJog2 = nullptr;
}

void GerenciadorColisoes::incluirInimigos(Inimigo* pI) {
    if (pI)
        listaInimigos.push_back(pI);
}

void GerenciadorColisoes::incluirObstaculo(Obstaculo* pO) {
    if (pO)
        listaObstaculos.push_back(pO);
}

void GerenciadorColisoes::incluirProjetil(Projetil* pJ) {
    if (pJ)
        listaProjeteis.insert(pJ);
}

void GerenciadorColisoes::checarColisoes(Personagem& personagem, const Floor& floor, const std::vector<Obstaculos::Plataforma>& plataformas) {
    sf::FloatRect characterBounds = personagem.getBounds();

    // First check collision with the floor
    for (const auto& tileBounds : floor.getBounds()) {
        if (characterBounds.intersects(tileBounds)) {
            if (personagem.getVelocityY() > 0.f) {
                float overlap = (characterBounds.top + characterBounds.height) - tileBounds.top;
                personagem.move({0.f, -overlap});
                personagem.stopFalling();
            }
            return;
        }
    }

    // Now check collision with each platform
    for (const auto& platform : plataformas) {
        for (const auto& tileBounds : platform.getBounds()) {
            if (characterBounds.intersects(tileBounds)) {
                if (personagem.getVelocityY() > 0.f) {
                    float overlap = (characterBounds.top + characterBounds.height) - tileBounds.top;
                    personagem.move({0.f, -overlap});
                    personagem.stopFalling();
                }
                return;
            }
        }
    }

    personagem.startFalling();
}

void GerenciadorColisoes::checarColisaoEntrePersonagens(Personagem& p1, Personagem& p2) {
    sf::FloatRect bounds1 = p1.getBounds();
    sf::FloatRect bounds2 = p2.getBounds();

    if (bounds1.intersects(bounds2)) {
        float knockbackSpeed = 500.f;
        float overlapX = (bounds1.left + bounds1.width / 2.f) - (bounds2.left + bounds2.width / 2.f);
        float direction = (overlapX > 0.f) ? 1.f : -1.f;

        p1.setVelocityX(direction * knockbackSpeed);
        p1.setVelocityY(-15.f);
        p1.setKnockbackTimer(30.f);

        // p2.setVelocityX(-direction * knockbackSpeed * 0.01f);

    }
}

const bool GerenciadorColisoes::verificarColisao(Personagem& p1, Personagem& p2) {
    sf::FloatRect bounds1 = p1.getBounds();
    sf::FloatRect bounds2 = p2.getBounds();

    if (bounds1.intersects(bounds2)) {
        return true;
    }
    return false;
}

void GerenciadorColisoes::tratarColisaoJogsInimigs(Jogador& jogador, Inimigo& inimigo) {
    if (verificarColisao(jogador, inimigo)) {
        inimigo.danificar(jogador);
    }
}


void GerenciadorColisoes::tratarColisaoProjeteis() {
    for (auto proj : listaProjeteis) {
        if (!proj || !proj->estaAtivo())
            continue;

        if (proj->getDono() == Dono::Jogador) {
            for (auto inimigo : listaInimigos) {
                if (!inimigo || !inimigo->isAlive)
                    continue;
                if (inimigo && proj->getBounds().intersects(inimigo->getBounds())) {
                    bool estavaVivo = inimigo->isAlive;
                    inimigo->tomarDano(1);
                    proj->desativar();
                    if (!inimigo->isAlive && estavaVivo) {
                        pJog1->addPontos(10); // No futuro, posso atribuir pts especificos p inimigo
                        pJog2->addPontos(10);
                    }
                    break;
                }
            }
        }
        else if (proj->getDono() == Dono::Inimigo) {
            if (pJog1 && proj->getBounds().intersects(pJog1->getBounds())) {
                pJog1->tomarDano(1);
                proj->desativar();
            }
            if (pJog2 && proj->getBounds().intersects(pJog2->getBounds())) {
                pJog2->tomarDano(1);
                proj->desativar();
            }
        }
    }
}


void GerenciadorColisoes::atualizarProjeteis(float dt) {
    for (auto it = listaProjeteis.begin(); it != listaProjeteis.end();) {
        (*it)->executar(dt);
        if (!(*it)->estaAtivo()) {
            delete *it;
            it = listaProjeteis.erase(it);
        } else {
            ++it;
        }
    }
}

void GerenciadorColisoes::renderizarProjeteis(sf::RenderWindow& window) {
    for (auto proj : listaProjeteis) {
        if (proj && proj->estaAtivo()) {
            proj->renderizar(window);  // ✅ uses Entidade::renderizar
        }
    }
}

void GerenciadorColisoes::removerProjeteisInativos() {
    for (auto it = listaProjeteis.begin(); it != listaProjeteis.end(); ) {
        if (!(*it)->estaAtivo()) {
            delete *it;
            it = listaProjeteis.erase(it);
        } else {
            ++it;
        }
    }
}

void GerenciadorColisoes::tratarColisaoJogsObstacs() {
    for (auto* obst : listaObstaculos) {
        sf::FloatRect bounds = obst->getBounds();       
        if (pJog1 && obst->getBounds().intersects(pJog1->getBounds())) {
            obst->obstaculizar(*pJog1);
        }
        if (pJog2 && obst->getBounds().intersects(pJog2->getBounds())) {
            obst->obstaculizar(*pJog2);
        }
    }
}