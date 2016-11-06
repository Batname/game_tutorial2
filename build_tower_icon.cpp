#include "build_tower_icon.h"
#include "game.h"
#include "tower.h"

#include <QString>

extern Game * game;
BuildTowerIcon::BuildTowerIcon(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/tower_icon.png"));
}

void BuildTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!game->build) {
        game->build = new Tower;
        game-> setCursor(QString(":images/tower.png"));
    }
}
