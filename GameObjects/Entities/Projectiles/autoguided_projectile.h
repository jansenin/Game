#pragma once

#include "projectile.h"

class AutoguidedProjectile : public Projectile {
 public:
  AutoguidedProjectile(const VectorF& coordinates,
                       QPixmap* pixmap,
                       Entity* target,
                       qreal start_speed,
                       qreal max_speed,
                       qreal acceleration,
                       qreal enemy_find_distance,
                       Damage damage);

  AutoguidedProjectile(const VectorF& coordinates,
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

  bool is_destroying_;
  Entity* target_;
  VectorF speed_;
  Damage damage_;
  qreal max_speed_;
  qreal acceleration_;
  qreal enemy_find_distance_;
};
