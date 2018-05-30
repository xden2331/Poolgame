#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "game.h"
#include "keyeventmanager.h"


class GameManager
{
public:
    GameManager();

private:
    Game* m_game;
    KeyEventManager* m_keyManager;
};

#endif // GAMEMANAGER_H
