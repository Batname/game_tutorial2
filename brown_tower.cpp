#include "brown_tower.h"
#include "tower.h"
#include "bullet.h"
#include "game.h"

#include <QTimer>
#include <QLineF>

extern Game * game;

BrownTower::BrownTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target/aquire_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquireTarget()));
    timer->start(1000);
}

void BrownTower::fire()
{
    int half_width = getTowerSize()["half_width"];
    int half_height = getTowerSize()["half_height"];

    Bullet * bullet = new Bullet();
    bullet->setPixmap(QPixmap(":/images/a3.png"));
    bullet->setPos(x()+half_width,y()+half_height);

    QLineF ln(QPointF(x()+half_width,y()+half_height),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void BrownTower::aquireTarget()
{
    Tower::aquireTarget();
}
