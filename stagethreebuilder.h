#ifndef STAGETHREEBUILDER_H
#define STAGETHREEBUILDER_H

#include "stagetwobuilder.h"
#include "stagethreegame.h"

class StageThreeBuilder : public GameBuilder
{
public:
    StageThreeBuilder(StageTwoBuilder* twoBuilder):
        m_twoBuilder(twoBuilder){}
    virtual ~StageThreeBuilder(){delete m_twoBuilder;}
private:
    StageTwoBuilder* m_twoBuilder;

    // GameBuilder interface
public:
    virtual void addBall(QJsonObject &ballData) override{
        m_twoBuilder->addBall(ballData);
    }
    virtual void addTable(QJsonObject &tableData) override{
        m_twoBuilder->addTable(tableData);
    }
    virtual Game* getResult() override{
        Game* baseGame = m_twoBuilder->getResult();
        return new StageThreeGame(baseGame);
    }
};

#endif // STAGETHREEBUILDER_H
