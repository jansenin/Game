#pragma once

#include "GameObjects/BasicObjects/Interface/entity.h"

class Tower : public Entity {
 public:
  Tower(const VectorF& coordinates, QPixmap* pixmap, int health = 0);
};
