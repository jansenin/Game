#ifndef TEST_PROJECTILE_H__
#define TEST_PROJECTILE_H__

#include "self_directed_projectile.h"

class TestProjectile : public SelfDirectedProjectile {
 public:
  TestProjectile(const QPointF& coordinates, Entity* target);

  void Tick(Time delta) override;
};

#endif //TEST_PROJECTILE_H__
