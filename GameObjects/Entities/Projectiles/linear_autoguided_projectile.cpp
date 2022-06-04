#include "linear_autoguided_projectile.h"

#include <algorithm>

#include <QGraphicsScene>

#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "GameObjects/explosion.h"
#include "constants.h"

LinearAutoguidedProjectile::LinearAutoguidedProjectile(
    const VectorF& coordinates,
    QPixmap* pixmap,
    Entity* target,
    qreal speed,
    Damage damage)
    : LinearAutoguidedProjectile(
        coordinates, new Animation(pixmap), target, speed, damage) {}

LinearAutoguidedProjectile::LinearAutoguidedProjectile(
    const VectorF& coordinates,
    Animation* animation,
    Entity* target,
    qreal speed,
    Damage damage)
    : Projectile(coordinates, animation),
    target_(target),
    speed_(speed),
    damage_(damage) {
  connect(target_, &Entity::destroyed, this,
          &LinearAutoguidedProjectile::Die);
}

void LinearAutoguidedProjectile::Tick(Time delta) {
  Projectile::Tick(delta);
  if (target_ == nullptr) {
    return;
  }
  if (target_->GetHealth() <= 0) {
    Die();
  }
  if (target_ == nullptr) {
    return;
  }

  Move(delta);

  if (target_->collidesWithItem(this)) {
    target_->ApplyDamage(damage_);
    scene()->addItem(
        new Explosion(
            scenePos(), 10, Damage(10)));
    deleteLater();
  }
}

void LinearAutoguidedProjectile::Move(Time delta) {
  if (target_ == nullptr) {
    return;
  }

  VectorF delta_pos =
      VectorFromThisToTarget().normalized() * speed_ * delta.seconds();

  MoveBy(delta_pos);
}

void LinearAutoguidedProjectile::SetTarget(Entity* target) {
  // TODO(jansenin): what if target_ is destroyed?
  disconnect(
      target_,
      &Entity::destroyed,
      this,
      &LinearAutoguidedProjectile::Die);
  target_ = target;
  if (target_ != nullptr) {
    connect(
        target_,
        &Entity::destroyed,
        this,
        &LinearAutoguidedProjectile::Die);
  }
}

VectorF LinearAutoguidedProjectile::VectorFromThisToTarget() {
  return target_->scenePos() - scenePos();
}

void LinearAutoguidedProjectile::Die() {
  SetTarget(nullptr);
  deleteLater();
}
