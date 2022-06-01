#include "mob.h"

#include <vector>

Mob::Mob(const VectorF& coordinates,
         Animation* animation,
         int health,
         qreal speed)
    : Entity(coordinates, animation, health),
      speed_(speed) {}

Mob::Mob(const VectorF& coordinates,
         Animation* animation,
         int health,
         qreal speed)
    : Mob(coordinates, new Animation(pixmap), health, speed) {}

Mob::Mob(const VectorF& coordinates,
         QPixmap* pixmap,
         int health,
         qreal speed)
    : Mob(coordinates, new Animation(pixmap), health, speed) {}

qreal Mob::GetSpeed() const {
  return speed_;
}

void Mob::SetSpeed(qreal speed) {
  speed_ = speed;
}

void Mob::SetRoute(Route* route) {
  if (route == nullptr && route_ != nullptr) {
    route_->RemoveEntity(this);
  }
  route_ = route;
  if (route_ != nullptr) {
    route_->AddEntity(this);
  }
}

void Mob::MoveToRouteStart() {
  Entity::setPos(route_->GetStart());
}
