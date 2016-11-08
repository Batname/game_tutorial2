#ifndef GREEN_TOWER_H
#define GREEN_TOWER_H

#include "tower.h"

class  GreenTower: public Tower
{
    Q_OBJECT
public:
     GreenTower(QGraphicsItem * parent = 0);
     void fire();
public slots:
     void aquireTarget();
};

#endif // GREEN_TOWER_H
