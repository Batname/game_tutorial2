#ifndef GAME_H
#define GAME_H

#include "tower.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QString>

class Game: public QGraphicsView
{
public:
    Game();
    void mousePressEvent(QMouseEvent *event);
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent * event);

    QGraphicsScene *scene;
    QGraphicsPixmapItem * cursor;
    Tower * build;

};

#endif // GAME_H
