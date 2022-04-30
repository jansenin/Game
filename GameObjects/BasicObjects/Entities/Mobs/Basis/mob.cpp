#include "mob.h"
#include <utility>

Mob::Mob(const VectorF& coordinates,
         QPixmap* pixmap,
         int health,
         Route&& route,
         qreal speed)
    : Entity(coordinates, pixmap, health),
      route_(std::move(route)),
      speed_(speed) {}

qreal Mob::GetSpeed() const {
  return speed_;
}

void Mob::SetSpeed(qreal speed) {
  speed_ = speed;
}
