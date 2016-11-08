#ifndef GAME_H
#define GAME_H

#include "tower.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QTimer>
#include <QList>
#include <QPointF>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    void mousePressEvent(QMouseEvent *event);
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent * event);
    void createEnemies(int number_of_enemies);
    void createRoad();

    QGraphicsScene *scene;
    QGraphicsPixmapItem * cursor;
    Tower * build;
    QTimer * spawn_timer;
    int enemies_spawned;
    int max_numbers_of_enemies;
    QList<QPointF> points_to_follow;

public slots:
    void spownEnemy();
};

#endif // GAME_H
