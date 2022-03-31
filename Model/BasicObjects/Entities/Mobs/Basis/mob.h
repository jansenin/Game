#ifndef MODEL_BASICOBJECTS_ENTITIES_MOBS_BASIS_MOB_H_
#define MODEL_BASICOBJECTS_ENTITIES_MOBS_BASIS_MOB_H_

#include "../../../Interface/entity.h"

class Mob : public Entity {
 public:
  Mob(QPointF coordinates, int health, qreal width, qreal height);
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_MOBS_BASIS_MOB_H_
