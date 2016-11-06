#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
    void fire();
public slots:
    void aquireTarget();
private:
    QGraphicsPolygonItem * attack_area;
    QPointF attack_dest;
    bool has_target;
    QPixmap qpixmap;
    int half_tower_height;
    int half_tower_width;

};

#endif // TOWER_H
