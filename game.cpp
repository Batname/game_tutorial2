#include "game.h"
#include "tower.h"
#include "bullet.h"
#include "enemy.h"
#include "build_tower_icon.h"

#include <QGraphicsScene>
#include <QPixmap>

Game::Game()
{
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    // set the scene
    setScene(scene);

    // create a tower
    Tower *t = new Tower();
    t->setPos(250,250);

    // add the tower
    scene->addItem(t);

    // set cursor
    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create enemy
    Enemy * enemy = new Enemy;
    scene->addItem(enemy);

    // build
    BuildTowerIcon * ic = new BuildTowerIcon;
    scene->addItem(ic);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if (build) {
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = nullptr;
        build = nullptr;
    } else {
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::setCursor(QString filename)
{
    if (cursor) {
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem;

    QImage img(filename);
    QImage scaled_img = img.scaled(64, 64, Qt::KeepAspectRatio);
    QPixmap qpixmap = QPixmap::fromImage(scaled_img);

    cursor->setPixmap(qpixmap);
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if (cursor) {
        cursor->setPos(event->pos());
    }
}
