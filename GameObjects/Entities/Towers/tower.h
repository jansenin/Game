#pragma once

#include "GameObjects/Interface/entity.h"

class Tower : public Entity {
 public:
  Tower(const VectorF& coordinates, QPixmap* pixmap, int health = 0);
  Tower(const VectorF& coordinates, Animation* animation, int health = 0);
};
