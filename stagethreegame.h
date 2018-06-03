#ifndef STAGETHREEGAME_H
#define STAGETHREEGAME_H

#include "game.h"

#include "memento.h"
#include "state.h"

class StageThreeGame : public Game
{
public:
    StageThreeGame(Game* game) : m_game(game){}
    virtual ~StageThreeGame(){delete m_game;}

    Memento* createMemento();

    void revertMemento(Memento& memento);

    std::vector<Ball*>* getBalls() const {return m_balls;}
private:
    Game* m_game;

    // Game interface
public:
    virtual void render(QPainter &painter) const override;
};

#endif // STAGETHREEGAME_H
