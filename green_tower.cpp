#include "green_tower.h"
#include "tower.h"
#include "bullet.h"
#include "game.h"

#include <QTimer>
#include <QLineF>
#include <QPixmap>

extern Game * game;

GreenTower::GreenTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target/aquire_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquireTarget()));
    timer->start(1000);
}

void GreenTower::fire()
{
    int half_width = getTowerSize()["half_width"];
    int half_height = getTowerSize()["half_height"];

    Bullet * bullet = new Bullet();
    // set graphics
    bullet->setPixmap(QPixmap(":/images/a2.png"));

    bullet->setPos(x()+half_width,y()+half_height);

    QLineF ln(QPointF(x()+half_width,y()+half_height),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void GreenTower::aquireTarget()
{
    Tower::aquireTarget();
}
