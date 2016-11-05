#include "tower.h"

#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsPolygonItem>
#include <QLineF>
#include <QImage>
#include <QDebug>

Tower::Tower(QGraphicsItem *parent)
{
    // set image
    QImage img(":/images/tower.png");
    QImage scaled_img = img.scaled(64, 64, Qt::KeepAspectRatio);

    // set the graphics
    QPixmap qpixmap = QPixmap::fromImage(scaled_img);
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
    QPointF tower_center(x() + qpixmap.height() / 2, y() + qpixmap.width() / 2);
    QLineF ln(poly_center, tower_center);
    attack_area->setPos(x() + ln.dx(), y() + ln.dy());
}
