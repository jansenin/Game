#ifndef MODEL_BASICOBJECTS_ENTITIES_PROJECTILES_TEST_PROJECTILE_H_
#define MODEL_BASICOBJECTS_ENTITIES_PROJECTILES_TEST_PROJECTILE_H_

#include "self_directed_projectile.h"

class TestProjectile : public SelfDirectedProjectile {
 public:
  TestProjectile(const QPointF& coordinates, Entity* target);

  void Tick(Time delta) override;
};

#endif  // MODEL_BASICOBJECTS_ENTITIES_PROJECTILES_TEST_PROJECTILE_H_
