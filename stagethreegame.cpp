#include "stagethreegame.h"

Memento* StageThreeGame::createMemento(){
    Memento* memento = new Memento();
    memento->setupMemento(*(this->m_game->m_balls));
    memento->setupMemento(*(this->m_table));
    return memento;
}

void StageThreeGame::revertMemento(Memento &memento){
    State* previous = memento.getMemento();
    auto preBalls = previous->getBalls();
    m_game->m_balls->clear();
    for(auto pb : preBalls){
        m_game->m_balls->push_back(pb->clone());
    }
    m_game->m_table = previous->getTable();
}

void StageThreeGame::render(QPainter &painter) const{
    m_game->render(painter);
}
