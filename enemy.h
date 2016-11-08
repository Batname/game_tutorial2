#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QList<QPointF> points_to_follow, QGraphicsItem * parent = 0);
    void rotateToPoint(QPointF p);

public slots:
    void moveForvard();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
};

#endif // ENEMY_H
