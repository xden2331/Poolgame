#ifndef STATE_H
#define STATE_H

#include "table.h"
#include "ball.h"

class State{
public:
    virtual ~State(){}

private:
    friend class Game;
    friend class Memento;
    State() : m_balls(std::vector<Ball*>()){}

    void setupBalls(const std::vector<Ball*>& balls){
        for(Ball* b:balls){
            m_balls.push_back(b->clone());
        }
    }
    std::vector<Ball*> getBalls() const {return m_balls;}
private:
    std::vector<Ball*> m_balls;
};

#endif // STATE_H
