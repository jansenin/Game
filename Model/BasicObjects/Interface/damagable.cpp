#include "damagable.h"
#include <cmath>
Damagable::Damagable(int health) {
  health_ = health;
}
void Damagable::ApplyDamage(Damage damage) {
  SetHealth(std::max(health_ - damage.GetDamage(), 0));
}
void Damagable::SetHealth(int health) {
  health_ = health;
}
