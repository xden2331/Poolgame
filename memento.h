#ifndef MEMENTO_H
#define MEMENTO_H

#include "state.h"
#include "ball.h"
#include <vector>

class Memento
{
public:
    virtual ~Memento(){
        delete m_state;
    }

private:
    friend class Game;
    Memento() : m_state(new State()){}
    void setupMemento(const std::vector<Ball*>& oriBalls){
        m_state->setupBalls(oriBalls);
    }
    State* getMemento() const {return m_state;}

private:
    State* m_state;
};

#endif // MEMENTO_H
