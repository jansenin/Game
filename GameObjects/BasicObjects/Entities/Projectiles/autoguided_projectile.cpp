#include <QGraphicsScene>

#include "autoguided_projectile.h"

AutoguidedProjectile::AutoguidedProjectile(
    const VectorF& coordinates,
    QPixmap* pixmap,
    Entity* target,
    qreal speed,
    Damage damage)
    : Projectile(coordinates, pixmap),
    target_(target), speed_(speed), damage_(damage) {}

void AutoguidedProjectile::Tick(Time delta) {
  Move(delta);

  if (target_->collidesWithItem(this)) {
    target_->ApplyDamage(damage_);
    deleteLater();
  }
}

void AutoguidedProjectile::Move(Time delta) {
  VectorF target_point = target_->scenePos();
  VectorF delta_pos = target_point - scenePos();
  VectorF velocity = delta_pos.normalized() * speed_;

  MoveBy(velocity * delta.seconds());
}
