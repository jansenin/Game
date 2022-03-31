#include "damage.h"

Damage::Damage(int damage) {
  damage_ = damage;
}

int Damage::GetDamage() const {
  return damage_;
}
