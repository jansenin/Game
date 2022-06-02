#pragma once
#include "Basis/mob.h"

class Skeleton : public Mob {
 public:
  explicit Skeleton(const VectorF& coordinates = {0, 0});
  void ApplyDamage(Damage damage) override;
  void SetRoute(Route* route) override;
  void Tick(Time delta) override;

 private:
  bool is_destroying_;

  Animation* walk_animation_;
  Animation* death_animation_;
};


