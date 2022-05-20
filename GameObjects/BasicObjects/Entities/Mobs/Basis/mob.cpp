#include "mob.h"
#include <utility>
#include <vector>

std::vector<Route> routes{Route({
  QPointF(50, 50),
  QPointF(300, 400),
  QPointF(-100, -50)})};  // TODO(parfen01): move in level

Mob::Mob(const VectorF& coordinates,
         Animation* animation,
         int health,
         qreal speed)
    : Entity(coordinates, animation, health),
      speed_(speed) {
  route_ = &routes[0];
  route_->AddEntity(this);
  Entity::setPos(route_->GetStart());
}

Mob::Mob(const VectorF& coordinates,
         QPixmap* pixmap,
         int health,
         qreal speed) : Mob(coordinates, new Animation(pixmap), health, speed) {}

qreal Mob::GetSpeed() const {
  return speed_;
}

void Mob::SetSpeed(qreal speed) {
  speed_ = speed;
}
