#include "game.h"
#include "brown_tower.h"
#include "bullet.h"
#include "enemy.h"
#include "tower.h"
#include "build_brown_tower_icon.h"
#include "build_green_tower_icon.h"
#include "build_red_tower_icon.h"

#include <QGraphicsScene>
#include <QPixmap>
#include <QList>
#include <QDebug>

Game::Game()
{
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1200,800);

    // set the scene
    setScene(scene);

    // set cursor
    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    setFixedSize(1200, 800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create enemy
    Enemy * enemy = new Enemy;
    scene->addItem(enemy);

    // build
    BuildBrownTowerIcon * bt = new BuildBrownTowerIcon;
    BuildGreenTowerIcon * gt = new BuildGreenTowerIcon;
    BuildRedTowerIcon * rt = new BuildRedTowerIcon;
    gt->setPos(x(), y() + 200);
    rt->setPos(x(), y() + 400);

    scene->addItem(bt);
    scene->addItem(gt);
    scene->addItem(rt);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if (build) {
        QList<QGraphicsItem *>  items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++) {
            if (dynamic_cast<Tower*>(items[i])) return;
        }

        int half_width = build->getTowerSize()["half_width"];
        int half_height = build->getTowerSize()["half_height"];

        scene->addItem(build);
        build->setPos(event->pos().x() - half_width, event->pos().y() - half_height);
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
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if (cursor) {
        int half_width = build->getTowerSize()["half_width"];
        int half_height = build->getTowerSize()["half_height"];
        cursor->setPos(event->pos().x() - half_width, event->pos().y() - half_height);
    }
}
