#include "bullet.h"

#include <QPixmap>
#include <Qtimer>
#include <qmath.h>

Bullet::Bullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // set graphics
    setPixmap(QPixmap(":/images/arrow.png"));

    // connect a timer to move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);
}

void Bullet::move() {
    int STEP_SIZE = 30;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x() + dx, y() + dy);
}

double Bullet::getMaxRange()
{

}

double Bullet::getDistanceTraveled()
{

}

void Bullet::setMaxRange(double rng)
{

}

void Bullet::setDistanceTraveled(double dist)
{

}
