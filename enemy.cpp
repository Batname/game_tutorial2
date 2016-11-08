#include "enemy.h"

#include <QPixmap>
#include <QTimer>
#include <QLineF>
#include <qmath.h>

Enemy::Enemy(QList<QPointF> points_to_follow, QGraphicsItem *parent) : point_index(0)
{
    setPixmap(QPixmap(":/images/enemy.png"));

    // set points
    points << points_to_follow;
    dest = points[0];
    rotateToPoint(dest);

    // connect timer
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveForvard()));
    timer->start(150);
}

void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(), p);
    setRotation(-1 * ln.angle());

}

void Enemy::moveForvard()
{
    // if close
    QLineF ln(pos(), dest);
    if (ln.length() < 5) {
        point_index++;
        if (point_index >= points.size()) return;
        dest = points[point_index];
        rotateToPoint(dest);
    }

    // move enamy
    int STEP_SIZE = 5;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x() + dx, y() + dy);
}
