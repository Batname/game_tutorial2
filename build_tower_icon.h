#ifndef BUILD_TOWER_ICON_H
#define BUILD_TOWER_ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class BuildTowerIcon: public QGraphicsPixmapItem
{
public:
    BuildTowerIcon(QGraphicsItem * parent = 0 );
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILD_TOWER_ICON_H
