#include <QGraphicsScene>

#include "autoguided_projectile.h"
#include "GameObjects/BasicObjects/Entities/Mobs/Basis/mob.h"

AutoguidedProjectile::AutoguidedProjectile(
    const VectorF& coordinates,
    Animation* animation,
    Entity* target,
    qreal speed,
    Damage damage)
    : Projectile(coordinates, animation),
    target_(target), speed_(speed), damage_(damage) {
  connect(target_, &Entity::destroyed, this,
          &AutoguidedProjectile::FindNewTargetOrDie);
}


AutoguidedProjectile::AutoguidedProjectile(
    const VectorF& coordinates,
    QPixmap* pixmap,
    Entity* target,
    qreal speed,
    Damage damage)
    : AutoguidedProjectile(
        coordinates,new Animation(pixmap), target, speed, damage) {}

void AutoguidedProjectile::Tick(Time delta) {
  Projectile::Tick(delta);
  if (target_ == nullptr) {
    return;
  }
  if (target_->GetHealth() <= 0) {
    FindNewTargetOrDie();
  }
  if (target_ == nullptr) {
    return;
  }

  Move(delta);

  if (target_->collidesWithItem(this)) {
    target_->ApplyDamage(damage_);
    deleteLater();
  }
}

void AutoguidedProjectile::Move(Time delta) {
  if (target_ == nullptr) {
    return;
  }
  VectorF target_point = target_->scenePos();
  VectorF delta_pos = target_point - scenePos();
  VectorF velocity = delta_pos.normalized() * speed_;

  MoveBy(velocity * delta.seconds());
}

void AutoguidedProjectile::FindNewTargetOrDie() {
  if (scene()->Mobs().empty()) {
    SetTarget(nullptr);
    deleteLater();
  } else {
    auto old_target = target_;
    for (auto new_target : scene()->Mobs()) {
      if (new_target != target_ && VectorF(new_target->scenePos() - scenePos()).length() < 100) {
        SetTarget(new_target);
        break;
      }
    }
    if (old_target == target_) {
      SetTarget(nullptr);
      deleteLater();
    }
  }
}

void AutoguidedProjectile::SetTarget(Entity* target) {
  // TODO(jansenin): what if target_ is destroyed?
  disconnect(
      target_,
      &Entity::destroyed,
      this,
      &AutoguidedProjectile::FindNewTargetOrDie);
  target_ = target;
  if (target_ != nullptr) {
    connect(
        target_,
        &Entity::destroyed,
        this,
        &AutoguidedProjectile::FindNewTargetOrDie);
  }
}
