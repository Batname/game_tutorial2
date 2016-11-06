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

public slots:
    void attackTarget();
private:
    QGraphicsPolygonItem *attack_area;
    QPointF attack_dest;
    QPixmap qpixmap;
    int half_tower_height;
    int half_tower_width;
};

#endif // TOWER_H
