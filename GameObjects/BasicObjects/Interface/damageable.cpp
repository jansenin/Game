#include "damageable.h"

#include <cmath>
#include <algorithm>

Damageable::Damageable(int health) {
  health_ = health;
}

void Damageable::ApplyDamage(Damage damage) {
  SetHealth(std::max(health_ - damage.GetDamage(), 0));
}

void Damageable::SetHealth(int health) {
  health_ = health;
}

int Damageable::GetHealth() {
  return health_;
}
