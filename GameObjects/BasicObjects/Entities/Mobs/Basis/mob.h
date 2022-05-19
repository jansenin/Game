#pragma once

#include <QPixmap>

#include "GameObjects/BasicObjects/Interface/entity.h"
#include "Utilities/vector_f.h"

class Mob : public Entity {
 public:
  Mob(const VectorF& coordinates, QPixmap* pixmap, int health = 0);
};
