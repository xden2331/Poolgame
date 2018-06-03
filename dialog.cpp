#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <QMouseEvent>
#include "utils.h"

int test = 0;

Dialog::Dialog(Game *game, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_game(game)
{
    ui->setupUi(this);

    // for animating (i.e. movement, collision) every animFrameMS
    aTimer = new QTimer(this);
    connect(aTimer, SIGNAL(timeout()), this, SLOT(nextAnim()));
    aTimer->start(animFrameMS);

    // for drawing every drawFrameMS milliseconds
    dTimer = new QTimer(this);
    connect(dTimer, SIGNAL(timeout()), this, SLOT(tryRender()));
    dTimer->start(drawFrameMS);

    // set the window size to be at least the table size
    this->resize(game->getMinimumWidth(), game->getMinimumHeight());

    m_gameManager = new GameManager(m_game, m_keyManager);
}

Dialog::~Dialog()
{
    delete aTimer;
    delete dTimer;
    delete m_game;
    delete ui;
}

void Dialog::tryRender() {
    this->update();
}

void Dialog::nextAnim() {
    m_game->animate(1.0/(double)animFrameMS);
    if(m_needMemento == true){
        m_gameManager->createMemento();
        m_needMemento = false;
    }
    if(test == 2){
        ++test;
    }
    if(m_keyManager->m_pressOnR){
        m_gameManager->revert();
        m_keyManager->m_pressOnR = false;
    }
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    m_gameManager->render(painter);
}

void Dialog::mousePressEvent(QMouseEvent* event) {
    CueBall* cue = dynamic_cast<CueBall*>(m_game->getBalls()->at(0));
    cue->mouseClickEvent(event);
}

void Dialog::mouseReleaseEvent(QMouseEvent* event) {
    CueBall* cue = dynamic_cast<CueBall*>(m_game->getBalls()->at(0));
    cue->mouseReleaseEvent(event);
}
void Dialog::mouseMoveEvent(QMouseEvent* event) {
    CueBall* cue = dynamic_cast<CueBall*>(m_game->getBalls()->at(0));
    cue->mouseMoveEvent(event);
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    m_keyManager->keyPressEvent(event);
}
