#pragma once
#include <QDialog>
#include "ball.h"
#include "game.h"
#include "gamemanager.h"
#include "keyeventmanager.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(Game* game, QWidget *parent = 0);
    ~Dialog();

protected:
    /**
     * @brief paintEvent - called whenever window repainting is requested
     */
    void paintEvent(QPaintEvent *);
public slots:
    /**
     * @brief nextAnim - move the objects and perform collision events
     */
    void nextAnim();
    /**
     * @brief tryRender - draw the objects to screen
     */
    void tryRender();

    // qt mouse click
    void mousePressEvent(QMouseEvent* event);
    // qt mouse release
    void mouseReleaseEvent(QMouseEvent* event);
    // qt mouse move
    void mouseMoveEvent(QMouseEvent* event);

private:
    /**
     * @brief aTimer - timer for calling nextAnim in intervals
     */
    QTimer* aTimer = nullptr;
    /**
     * @brief dTimer - timer for calling tryRender in intervals
     */
    QTimer* dTimer = nullptr;
    /**
     * @brief ui our drawable ui
     */
    Ui::Dialog *ui;
    /**
     * @brief m_game - our game object to be played
     */
    Game* m_game = nullptr;

    GameManager* m_gameManager = nullptr;

    KeyEventManager* m_keyManager = new KeyEventManager();

    bool m_needMemento = true;
    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

