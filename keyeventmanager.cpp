#include "keyeventmanager.h"

void KeyEventManager::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if(key == Qt::Key_Escape){
        m_pressOnEsc = !m_pressOnEsc;
    }
    if(key == Qt::Key_R){
        m_pressOnR = true;
    }
}

void KeyEventManager::keyReleaseEvent(QKeyEvent *event)
{
    int key = event->key();
    if(key == Qt::Key_R){
        m_pressOnR = false;
    }
}
