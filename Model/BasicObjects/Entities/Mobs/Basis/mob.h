#ifndef MOB_H
#define MOB_H

#include "../../../Interface/entity.h"

class Mob : public Entity {
 public:
  Mob(QPointF coordinates, int health, qreal width, qreal height);
};

#endif //MOB_H
