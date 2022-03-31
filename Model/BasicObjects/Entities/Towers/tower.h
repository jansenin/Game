#ifndef MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWER_H_
#define MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWER_H_

#include "../../Interface/entity.h"

class Tower : public Entity {
 public:
  Tower(QPointF coordinates, int health, qreal width, qreal height);
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWER_H_
