#pragma once

#include "GameObjects/Interface/entity.h"

class Projectile : public Entity {
 public:
  Projectile(const VectorF& coordinates, QPixmap* pixmap);
  Projectile(const VectorF& coordinates, Animation* animation);
};


