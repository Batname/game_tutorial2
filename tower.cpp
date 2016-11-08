#include "tower.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"

#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QPointF>
#include <QLineF>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QImage>
#include <QHash>
#include <QString>

extern Game * game;

#include <QDebug>
Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 75;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // set tower size
    tower_size.insert("half_width", 64);
    tower_size.insert("half_height", 64);

    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->setPen(QPen(Qt::DotLine));

    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(x()+64,y()+64);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    // set attack_dest
    attack_dest = QPointF(0,0);
    has_target = false;
}

double Tower::distanceTo(QGraphicsItem *item){
    // returns the distance to the item
    QLineF ln(this->pos(),item->pos());
    return ln.length();
}

void Tower::fire(){
    int half_width = getTowerSize()["half_width"];
    int half_height = getTowerSize()["half_height"];

    Bullet * bullet = new Bullet();
    bullet->setPos(x()+half_width,y()+half_height);

    QLineF ln(QPointF(x()+half_width,y()+half_height),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

QHash<QString, int> Tower::getTowerSize()
{
    return tower_size;
}

void Tower::aquireTarget(){
    // get a list of all enemies that collide with attack_area, find the closest one
    // and set it's position as the attack_dest

    // get a list of all enemies within attack_area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    // assume tower does not have a target, unless we find one
    has_target = false;

    // find the closest Enemy
    double closest_dist = 300;
    QPointF closest_pt(0,0);
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){

        // make sure it is an enemy
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);

        // see if distance is closer
        if (enemy){
            double this_dist = distanceTo(colliding_items[i]);
            if (this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }

    // if has target, set the closest enemy as the attack_dest, and fire
    if (has_target){
        attack_dest = closest_pt;
        fire();
    }
}
