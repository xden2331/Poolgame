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

    void setupTable(const Table& table){
        m_table = table.clone();
    }

    std::vector<Ball*> getBalls() const {return m_balls;}
    Table* getTable() const { return m_table; }
private:
    std::vector<Ball*> m_balls;
    Table* m_table;
};

#endif // STATE_H
