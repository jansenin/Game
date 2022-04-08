#include "mob.h"

Mob::Mob(QPointF coordinates, QString path_to_pixmap, int health)
  : Entity(coordinates, path_to_pixmap, health) {}
