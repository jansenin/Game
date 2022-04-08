#ifndef MODEL_BASICOBJECTS_ENTITIES_PROJECTILES_SELF_DIRECTED_PROJECTILE_H_
#define MODEL_BASICOBJECTS_ENTITIES_PROJECTILES_SELF_DIRECTED_PROJECTILE_H_

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

#endif  // MODEL_BASICOBJECTS_ENTITIES_PROJECTILES_SELF_DIRECTED_PROJECTILE_H_
