#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QPixmap>

class Tower: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tower(QGraphicsItem *parent = 0);
    double distanceTo(QGraphicsItem * item);
    void fire();
public slots:
    void aquireTarget();
private:
    QGraphicsPolygonItem *attack_area;
    QPointF attack_dest;
    QPixmap qpixmap;
    int half_tower_height;
    int half_tower_width;
    bool has_target;
};

#endif // TOWER_H
