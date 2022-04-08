#include "test_projectile.h"

#include "Utilities/math.h"

TestProjectile::TestProjectile(const QPointF& coordinates, Entity* target)
  : SelfDirectedProjectile(
    coordinates,
    ":/images/test_bullet.png",
    target,
    10,
    Damage(10)) {}

void TestProjectile::Tick(Time delta) {
  SelfDirectedProjectile::Tick(delta);
}
