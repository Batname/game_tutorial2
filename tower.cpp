#include "tower.h"
#include "bullet.h"
#include "game.h"
#include "enemy.h"

#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsPolygonItem>
#include <QLineF>
#include <QImage>
#include <QDebug>
#include <QPointF>
#include <QTimer>

extern Game * game;

Tower::Tower(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // set image
    QImage img(":/images/tower.png");
    QImage scaled_img = img.scaled(64, 64, Qt::KeepAspectRatio);

    // set the graphics
    qpixmap = QPixmap::fromImage(scaled_img);
    half_tower_height = qpixmap.height() / 2;
    half_tower_width = qpixmap.width() / 2;
    setPixmap(qpixmap);

    // create point vector
    QVector<QPointF> points;
    points << QPointF(1,0) << QPointF(2,0) << QPointF(3,1)
           << QPointF(3,2) << QPointF(2,3) << QPointF(1,3)
           << QPointF(0,2) << QPointF(0,1);

    // scale points
    int SCALE_FACTOR = 40;
    for (size_t i = 0, n = points.size(); i < n; i++) {
        points[i] *= SCALE_FACTOR;
    }

    // create a polygon from points
    QPolygonF polygon(points);

    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(polygon, this);

    // move the polygon
    QPointF poly_center(1.5, 1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x() + half_tower_height, y() + half_tower_width);
    QLineF ln(poly_center, tower_center);
    attack_area->setPos(x() + ln.dx(), y() + ln.dy());

    // connect a timer to attackTarget
    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(aquireTarget()));

    timer->start(1000);

    // set attack_dest;
    attack_dest = QPointF(800, 0);
}

double Tower::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(), item->pos());
    return ln.length();
}

void Tower::fire()
{
    Bullet * bullet = new Bullet;

    bullet->setPos(x() + half_tower_height, y() + half_tower_width);

    QLineF ln(QPointF(half_tower_height, half_tower_width), attack_dest);
    int angle = -1 * ln.angle();
    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower::aquireTarget()
{
    // get list of all colliding with attack_area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if (colliding_items.size() == 1) {
        has_target = false;
        return;
    }

    double closest_dist = 300;
    QPointF closest_pt(0, 0);

    for (size_t i = 0, n = colliding_items.size(); i < n; i++) {
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if (enemy) {
            double this_dist = distanceTo(enemy);
            if (this_dist < closest_dist) {
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }

    attack_dest = closest_pt;
    fire();
}
