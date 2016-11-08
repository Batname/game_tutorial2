#ifndef BUILD_BROWN_TOWER_ICON_H
#define BUILD_BROWN_TOWER_ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class BuildBrownTowerIcon: public QGraphicsPixmapItem
{
public:
    BuildBrownTowerIcon(QGraphicsItem * parent = 0 );
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILD_BROWN_TOWER_ICON_H
