#include "mob.h"

Mob::Mob(const VectorF& coordinates, QPixmap* pixmap, int health, qreal speed)
    : Entity(coordinates, pixmap, health), speed_(speed) {}

qreal Mob::GetSpeed() const {
  return speed_;
}

void Mob::SetSpeed(qreal speed) {
  speed_ = speed;
}
