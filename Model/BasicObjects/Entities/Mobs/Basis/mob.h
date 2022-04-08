#ifndef MODEL_BASICOBJECTS_ENTITIES_MOBS_BASIS_MOB_H_
#define MODEL_BASICOBJECTS_ENTITIES_MOBS_BASIS_MOB_H_

#include "../../../Interface/entity.h"

#include <QPixmap>

class Mob : public Entity {
 public:
  Mob(QPointF coordinates, QString path_to_pixmap, int health = 0);
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_MOBS_BASIS_MOB_H_
