#pragma once

#include "projectile.h"

class LinearAutoguidedProjectile : public Projectile {
 public:
  LinearAutoguidedProjectile(
      const VectorF& coordinates,
      QPixmap* pixmap,
      Entity* target,
      qreal speed,
      Damage damage);

  LinearAutoguidedProjectile(
      const VectorF& coordinates,
      Animation* animation,
      Entity* target,
      qreal speed,
      Damage damage);

  void SetTarget(Entity* target);

  void Tick(Time delta) override;

 protected:
  void Move(Time delta);
  void Die();
  VectorF VectorFromThisToTarget();

  Entity* target_;
  qreal speed_;
  Damage damage_;
};


