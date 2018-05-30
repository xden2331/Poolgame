#include "gamemanager.h"

GameManager::GameManager(Game *game, KeyEventManager *keyManager)
    : m_game(game), m_keyManager(keyManager)
{
    int width = 1000;
    int height = 500;
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
