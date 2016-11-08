#ifndef BUILD_RED_TOWER_ICON_H
#define BUILD_RED_TOWER_ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class BuildRedTowerIcon: public QGraphicsPixmapItem
{
public:
    BuildRedTowerIcon(QGraphicsItem * parent = 0 );
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};


#endif // BUILD_RED_TOWER_ICON_H
