#pragma once

#include "GameObjects/BasicObjects/Interface/entity.h"

class Projectile : public Entity {
 public:
  Projectile(const VectorF& coordinates, QPixmap* pixmap);
};


