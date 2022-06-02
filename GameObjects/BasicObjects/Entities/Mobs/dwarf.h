#pragma once
#include "Basis/mob.h"


class Dwarf : public Mob {
 public:
  explicit Dwarf(const VectorF& coordinates = {0, 0});
  void ApplyDamage(Damage damage) override;
  void SetRoute(Route* route) override;
  void Tick(Time delta) override;

  QRectF boundingRect() const override;

 private:
  bool is_destroying_;

  Animation* walk_animation_;
  Animation* death_animation_;
};

