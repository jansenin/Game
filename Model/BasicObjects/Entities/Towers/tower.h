#ifndef MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWER_H_
#define MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWER_H_

#include "../../Interface/entity.h"

class Tower : public Entity {
 public:
  Tower(QPointF coordinates, int health, qreal width, qreal height, int price, qreal range);
  [[nodiscard]] int GetPrice() const;

 protected:
  int price_;
  qreal range_;
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_TOWERS_TOWER_H_
