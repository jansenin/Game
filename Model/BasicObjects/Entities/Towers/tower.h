#ifndef TOWER_H
#define TOWER_H

#include "../../Interface/entity.h"

class Tower : public Entity {
 public:
  Tower(QPointF coordinates, int health, qreal width, qreal height);
};

#endif //TOWER_H
