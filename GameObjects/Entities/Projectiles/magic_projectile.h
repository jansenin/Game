#pragma once

#include "autoguided_projectile.h"

class MagicProjectile : public AutoguidedProjectile {
 public:
  MagicProjectile(const VectorF& coordinates, Entity* target, int level);

  void Tick(Time delta) override;

 private:
  Animation* destroying_animation_;
};
