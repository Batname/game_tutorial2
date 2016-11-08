#ifndef BUILD_GREEN_TOWER_ICON_H
#define BUILD_GREEN_TOWER_ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class BuildGreenTowerIcon: public QGraphicsPixmapItem
{
public:
    BuildGreenTowerIcon(QGraphicsItem * parent = 0 );
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILD_GREEN_TOWER_ICON_H
