#ifndef RED_TOWER_H
#define RED_TOWER_H

#include "tower.h"

class  RedTower: public Tower
{
    Q_OBJECT
public:
     RedTower(QGraphicsItem * parent = 0);
     void fire();
public slots:
     void aquireTarget();
};

#endif // RED_TOWER_H
