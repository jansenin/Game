#pragma once

#include "Utilities/damage.h"

class Damageable {
 public:
  explicit Damageable(int health);
  virtual void ApplyDamage(Damage damage);
  int GetHealth();

 protected:
  int health_;
  virtual void SetHealth(int health);
};
