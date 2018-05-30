#ifndef KEYEVENTMANAGER_H
#define KEYEVENTMANAGER_H

#include <QWidget>
#include <QKeyEvent>

class KeyEventManager : public QWidget
{
public:
    KeyEventManager() = delete;
    bool m_pressOnEsc = false;
    bool m_pressOnR = false;

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // KEYEVENTMANAGER_H
