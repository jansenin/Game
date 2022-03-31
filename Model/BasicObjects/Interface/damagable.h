#ifndef DAMAGABLE_H
#define DAMAGABLE_H

#include "../../../Utilities/damage.h"

class Damagable {
 public:
  Damagable(int health);
  virtual void ApplyDamage(Damage damage);
 private:
  int health_;
  virtual void SetHealth(int health);
};

#endif //DAMAGABLE_H
