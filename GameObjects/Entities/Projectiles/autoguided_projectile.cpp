#include "autoguided_projectile.h"

#include <algorithm>

#include <QGraphicsScene>

#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "constants.h"

AutoguidedProjectile::AutoguidedProjectile(
    const VectorF& coordinates,
    Animation* animation,
    Entity* target,
    qreal start_speed,
    qreal max_speed,
    qreal acceleration,
    qreal enemy_find_distance,
    Damage damage)
    : Projectile(coordinates, animation),
    target_(target),
    speed_(
        VectorF(target->scenePos() - scenePos()).normalized() * start_speed),
    max_speed_(max_speed),
    acceleration_(acceleration),
    enemy_find_distance_(enemy_find_distance),
    damage_(damage) {
  connect(target_, &Entity::destroyed, this,
          &AutoguidedProjectile::FindNewTargetOrDie);
}

AutoguidedProjectile::AutoguidedProjectile(
    const VectorF& coordinates,
    QPixmap* pixmap,
    Entity* target,
    qreal start_speed,
    qreal max_speed,
    qreal acceleration,
    qreal enemy_find_distance,
    Damage damage)
    : AutoguidedProjectile(
        coordinates,
        new Animation(pixmap),
        target,
        start_speed,
        max_speed,
        acceleration,
        enemy_find_distance,
        damage) {}

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

  VectorF delta_velocity =
      VectorFromThisToTarget().normalized() * acceleration_ * delta.seconds();

  speed_ += delta_velocity;

  qreal speed_scalar = speed_.length();
  speed_ = speed_.normalized() * std::min(max_speed_, speed_scalar);

  MoveBy(speed_ * delta.seconds());
}

void AutoguidedProjectile::FindNewTargetOrDie() {
  if (scene()->Mobs().empty()) {
    SetTarget(nullptr);
    deleteLater();
  } else {
    auto old_target = target_;
    for (auto new_target : scene()->Mobs()) {
      VectorF this_to_target_vector =
          VectorF(new_target->scenePos() - scenePos());

      if (new_target != target_ &&
          this_to_target_vector.length() < enemy_find_distance_ &&
          new_target->GetHealth() > 0) {
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

VectorF AutoguidedProjectile::VectorFromThisToTarget() {
  return target_->scenePos() - scenePos();
}
