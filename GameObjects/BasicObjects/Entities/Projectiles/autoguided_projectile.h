#pragma once

#include "GameObjects/BasicObjects/Entities/Projectiles/projectile.h"

class AutoguidedProjectile : public Projectile {
 public:
  AutoguidedProjectile(const VectorF& coordinates,
                       QPixmap* pixmap,
                       Entity* target, qreal speed, Damage damage);

  void Tick(Time delta) override;

 protected:
  void Move(Time delta);

  Entity* target_;
  qreal speed_;
  Damage damage_;
};
