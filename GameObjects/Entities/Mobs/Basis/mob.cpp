#include "mob.h"

#include <vector>

#include "Controller/controller.h"

Mob::Mob(const VectorF& coordinates,
         Animation* animation,
         int health,
         int damage_to_base,
         qreal speed)
    : Entity(coordinates, animation, health),
      speed_(speed),
      dealed_damage_to_base_(false),
      damage_to_base_(damage_to_base) {}

Mob::Mob(const VectorF& coordinates,
         QPixmap* pixmap,
         int health,
         int damage_to_base,
         qreal speed)
    : Mob(coordinates, new Animation(pixmap), health, damage_to_base, speed) {}

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

void Mob::Tick(Time delta) {
  Entity::Tick(delta);

  if (route_ != nullptr) {
    if (route_->isEnd(this) && !dealed_damage_to_base_) {
      dealed_damage_to_base_ = true;
      Controller::Instance()->DealDamageToBase(damage_to_base_);
    }
  }
}

Mob::~Mob() {
  if (route_ != nullptr) {
    route_->RemoveEntity(this);
  }
}

QRectF Mob::boundingRect() const {
  QRectF result = Entity::boundingRect();
  result.translate(0, -result.height() / 2);
  return result;
}
