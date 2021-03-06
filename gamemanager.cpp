#include "gamemanager.h"

GameManager::GameManager(Game *game, KeyEventManager *keyManager)
    : m_game(game), m_keyManager(keyManager), m_memento(new std::vector<Memento*>())
{
    int width = m_game->getMinimumWidth();
    int height = m_game->getMinimumHeight();
    m_rect = new QRect(QPoint(width/4, height/4),
                       QPoint(width*0.75, height*0.75));
}

void GameManager::render(QPainter &painter) const
{
    m_game->render(painter);
    if(m_keyManager->m_pressOnEsc){
        painter.drawRect(*m_rect);
    }
}

void GameManager::revert(){
    m_game->revertMemento(*(m_memento->at(0)));
}

void GameManager::createMemento(){
    Memento* memento = m_game->createMemento();
    m_memento->push_back(memento);
}
