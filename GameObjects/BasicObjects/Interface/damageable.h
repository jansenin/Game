#pragma once

#include "Utilities/damage.h"

class Damageable {
 public:
  explicit Damageable(int health);
  virtual void ApplyDamage(Damage damage);

 protected:
  int health_;
  virtual void SetHealth(int health);
};
