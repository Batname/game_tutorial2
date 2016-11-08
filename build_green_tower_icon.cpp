#include "build_green_tower_icon.h"
#include "game.h"
#include "green_tower.h"

#include <QString>

extern Game * game;
BuildGreenTowerIcon::BuildGreenTowerIcon(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/green_tower.png"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!game->build) {
        game->build = new GreenTower;
        game-> setCursor(QString(":images/green_tower.png"));
    }
}
