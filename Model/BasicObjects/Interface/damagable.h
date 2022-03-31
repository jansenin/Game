#ifndef MODEL_BASICOBJECTS_INTERFACE_DAMAGABLE_H_
#define MODEL_BASICOBJECTS_INTERFACE_DAMAGABLE_H_

#include "../../../Utilities/damage.h"

class Damagable {
 public:
  explicit Damagable(int health);
  virtual void ApplyDamage(Damage damage);

 private:
  int health_;
  virtual void SetHealth(int health);
};

#endif  // MODEL_BASICOBJECTS_INTERFACE_DAMAGABLE_H_
