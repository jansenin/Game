#pragma once

#include "projectile.h"
#include "Utilities/vector_f.h"

class AutoguidedProjectile : public Projectile {
 public:
  AutoguidedProjectile(
      const VectorF& coordinates,
      QPixmap* pixmap,
      Entity* target,
      qreal start_speed,
      qreal max_speed,
      qreal acceleration,
      qreal enemy_find_distance,
      Damage damage);

  AutoguidedProjectile(
      const VectorF& coordinates,
      Animation* animation,
      Entity* target,
      qreal start_speed,
      qreal max_speed,
      qreal acceleration,
      qreal enemy_find_distance,
      Damage damage);

  void SetTarget(Entity* target);

  void Tick(Time delta) override;

 protected:
  void Move(Time delta);
  void FindNewTargetOrDie();

  VectorF VectorFromThisToTarget();

  Entity* target_;
  Damage damage_;
  VectorF speed_;
  qreal acceleration_;
  qreal max_speed_;
  qreal enemy_find_distance_;
};
