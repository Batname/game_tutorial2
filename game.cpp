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
#include <QPointF>
#include <QLineF>
#include <QGraphicsLineItem>

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
    spawn_timer = new QTimer(this);
    enemies_spawned = 0;
    max_numbers_of_enemies = 0;
    points_to_follow << QPointF(1200,0) << QPointF(650,650) << QPointF(0,850);

    createEnemies(5);

    // create road
    createRoad();

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

void Game::createEnemies(int number_of_enemies)
{
    enemies_spawned = 0;
    max_numbers_of_enemies = number_of_enemies;
    connect(spawn_timer,SIGNAL(timeout()), this, SLOT(spownEnemy()));
    spawn_timer->start(1000);
}

void Game::createRoad()
{
    for (size_t i = 0, n = points_to_follow.size() - 1; i < n; i++) {
        // create line
        QLineF line(points_to_follow[i], points_to_follow[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setWidth(15);
        pen.setColor(Qt::darkGray);

        lineItem->setPen(pen);
        scene->addItem(lineItem);
    }
}

void Game::spownEnemy()
{
    // spown enemy
    Enemy * enemy = new Enemy(points_to_follow);
    enemy->setPos(points_to_follow[0]);
    scene->addItem(enemy);
    enemies_spawned++;

    if (enemies_spawned >= max_numbers_of_enemies) {
        spawn_timer->disconnect();
    }
}
