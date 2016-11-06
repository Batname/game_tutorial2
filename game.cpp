#include "game.h"
#include "tower.h"
#include "bullet.h"

#include <QGraphicsScene>

Game::Game()
{
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    // set the scene
    setScene(scene);

    // create a tower
    Tower *t = new Tower();
    t->setPos(250, 250);

    // add the tower
    scene->addItem(t);

    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    // create a bullet
    Bullet * bullet = new Bullet;
    bullet->setPos(event->pos());
    bullet->setRotation(40);
    scene->addItem(bullet);
}
