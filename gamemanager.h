#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "game.h"
#include "keyeventmanager.h"
#include "memento.h"
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
        for(auto m:*m_memento) delete m;
        delete m_memento;
    }

    void render(QPainter& painter) const;

    void createMemento();

    void revert();

private:
    Game* m_game;
    KeyEventManager* m_keyManager;
    QRect* m_rect;
    std::vector<Memento*>* m_memento;
};

#endif // GAMEMANAGER_H
