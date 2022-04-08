#ifndef SELF_DIRECTED_PROJECTILE_H__
#define SELF_DIRECTED_PROJECTILE_H__

#include "Model/BasicObjects/Interface/entity.h"

class SelfDirectedProjectile : public Entity {
 public:
  SelfDirectedProjectile(const QPointF& coordinates,
                         const QString& path_to_pixmap,
                         Entity* target, qreal speed, Damage damage);

  void Tick(Time delta) override;

 protected:
  void Move(Time delta);

  Entity* target_;
  qreal speed_;
  Damage damage_;
};

#endif //SELF_DIRECTED_PROJECTILE_H__
