#ifndef KEYEVENTMANAGER_H
#define KEYEVENTMANAGER_H

#include <QWidget>
#include <QKeyEvent>

class KeyEventManager : public QWidget
{
public:
    KeyEventManager(){}
    ~KeyEventManager(){}
    bool m_pressOnEsc = false;
    bool m_pressOnR = false;

    // QWidget interface
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // KEYEVENTMANAGER_H
