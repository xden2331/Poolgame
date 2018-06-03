#include "balldecorator.h"


void CueBall::render(QPainter &painter, const QVector2D &offset) {
    m_subBall->render(painter, offset);
    // stop drawing the line if we're moving at all
    if (isSubBallMoving()) {
        isDragging = false;
    }else{
        m_subBall->setVelocity(QVector2D(0,0));
    }
    if (isDragging) {
        painter.drawLine(m_startMousePos.toPointF(), m_endMousePos.toPointF());
    }
}

void CueBall::mouseClickEvent(QMouseEvent* e) {

    QVector2D p = QVector2D(e->pos());

    // don't allow movement if moving
    if (isSubBallMoving()) {
        // can't be too sure
        isDragging = false;
        return;
    }

    m_startMousePos = p;
    m_endMousePos = p;

    // note this treats it as absolute distance
    // check whether the click isn't on the ball
    if (m_startMousePos.distanceToPoint(m_subBall->getPosition()) > m_subBall->getRadius()) return;

    isDragging = true;

}

void CueBall::mouseMoveEvent(QMouseEvent* e) {
    QVector2D p = QVector2D(e->pos());

    if (isSubBallMoving()) {
        isDragging = false;
        return;
    }
    m_endMousePos = p;
}

void CueBall::mouseReleaseEvent(QMouseEvent* e) {
    QVector2D p = QVector2D(e->pos());
    
    // only draw & move if we're allowing the draw action to go ahead
    if (isDragging) {
        // velocity is the vector that the mouse drew
        m_endMousePos = p;
        QVector2D resultingVel = m_endMousePos - m_startMousePos;
        isDragging = false;
        // update ball vel
        m_subBall->changeVelocity(resultingVel);
    }
}
