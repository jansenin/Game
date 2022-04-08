#include <QGraphicsScene>

#include "self_directed_projectile.h"
#include "Utilities/math.h"

SelfDirectedProjectile::SelfDirectedProjectile(
    const QPointF& coordinates,
    const QString& path_to_pixmap,
    Entity* target,
    qreal speed,
    Damage damage)
    : Entity(coordinates, path_to_pixmap),
    target_(target), speed_(speed), damage_(damage) {}

void SelfDirectedProjectile::Tick(Time delta) {
  Move(delta);

  if (target_->collidesWithItem(this)) {
    target_->ApplyDamage(damage_);
    deleteLater();
  }
}

void SelfDirectedProjectile::Move(Time delta) {
  QPointF target_point = target_->scenePos();
  QPointF delta_pos = target_point - scenePos();
  QPointF velocity = Normalized(delta_pos) * speed_;

  MoveBy(velocity * delta.seconds());
  update();
}
