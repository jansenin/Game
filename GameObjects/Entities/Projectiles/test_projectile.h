#pragma once

#include "autoguided_projectile.h"

class TestProjectile : public AutoguidedProjectile {
 public:
  TestProjectile(const VectorF& coordinates, Entity* target);

  void Tick(Time delta) override;

 private:
  Time cross_cycle_time_;
};
