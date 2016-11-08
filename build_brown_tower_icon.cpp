#include "build_brown_tower_icon.h"
#include "game.h"
#include "brown_tower.h"

#include <QString>

extern Game * game;
BuildBrownTowerIcon::BuildBrownTowerIcon(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/brown_tower.png"));
}

void BuildBrownTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!game->build) {
        game->build = new BrownTower;
        game-> setCursor(QString(":images/brown_tower.png"));
    }
}
