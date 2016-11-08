#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent = 0);

public slots:
    void move();
    double getMaxRange();
    double getDistanceTraveled();
    void setMaxRange(double rng);
    void setDistanceTraveled(double dist);
private:
    double max_range;
    double distance_traveled;
};

#endif // BULLET_H
