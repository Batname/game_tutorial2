#include "build_red_tower_icon.h"
#include "game.h"
#include "red_tower.h"

#include <QString>

extern Game * game;
BuildRedTowerIcon::BuildRedTowerIcon(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/red_tower.png"));
}

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!game->build) {
        game->build = new RedTower;
        game->setCursor(QString(":images/red_tower.png"));
    }
}
