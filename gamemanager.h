#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "game.h"
#include "keyeventmanager.h"
#include <QRect>


class GameManager
{
public:
    explicit GameManager(Game* game,
                         KeyEventManager* keyManager);
    virtual ~GameManager(){
        delete m_game;
        delete m_keyManager;
        delete m_rect;
    }

    void render(QPainter& painter) const;

private:
    Game* m_game;
    KeyEventManager* m_keyManager;
    QRect* m_rect;
};

#endif // GAMEMANAGER_H
