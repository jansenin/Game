#pragma once

#include "linear_autoguided_projectile.h"

class CannonProjectile : public LinearAutoguidedProjectile {
 public:
  CannonProjectile(const VectorF& coordinates, Entity* target, int level);

  void Tick(Time delta) override;
};
