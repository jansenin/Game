#pragma once
#include "Basis/mob.h"

class Hedgehog : public Mob {
 public:
  explicit Hedgehog(const VectorF& coordinates = {0, 0});
  void ApplyDamage(Damage damage) override;
  void SetRoute(Route* route) override;
  void Tick(Time delta) override;

 private:
  bool is_destroying_;

  Animation* walk_animation_;
  Animation* death_animation_;
};

