#pragma once

#include "GameObjects/BasicObjects/Interface/entity.h"

class AutoguidedProjectile : public Entity {
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
