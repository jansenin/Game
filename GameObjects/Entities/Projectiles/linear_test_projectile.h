#pragma once

#include "linear_autoguided_projectile.h"

class LinearTestProjectile : public LinearAutoguidedProjectile {
 public:
  LinearTestProjectile(const VectorF& coordinates, Entity* target);

  void Tick(Time delta) override;
};
