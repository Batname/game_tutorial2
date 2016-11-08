#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QHash>
#include <QString>

class Tower:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
    virtual void fire();
    QHash<QString, int> getTowerSize();
public slots:
    void aquireTarget();
protected:
    QGraphicsPolygonItem * attack_area;
    QPointF attack_dest;
    bool has_target;
private:
    QHash<QString, int> tower_size;
};

#endif // TOWER_H
