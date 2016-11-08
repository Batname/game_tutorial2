#ifndef BROWN_TOWER_H
#define BROWN_TOWER_H

#include "tower.h"

class  BrownTower: public Tower
{
    Q_OBJECT
public:
     BrownTower(QGraphicsItem * parent = 0);
     void fire();
public slots:
     void aquireTarget();
};

#endif // BROWN_TOWER_H
