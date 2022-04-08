#ifndef MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWER_H_
#define MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWER_H_

#include "../../Interface/entity.h"

class Tower : public Entity {
 public:
  Tower(QPointF coordinates, QString path_to_pixmap, int health = 0);
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWER_H_
