#include "test_projectile.h"

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

TestProjectile::TestProjectile(const VectorF& coordinates, Entity* target)
  : AutoguidedProjectile(
    coordinates,
    PixmapLoader::Pixmaps::kTestBullet,
    target,
    Entities::TestProjectile::kSpeed,
    Entities::TestProjectile::kMaxSpeed,
    Entities::TestProjectile::kAcceleration,
    Entities::TestProjectile::kEnemyFindDistance,
    Entities::TestProjectile::kDamage),
    cross_cycle_time_(
        Entities::TestProjectile::kCrossAccelerationCycleDuration) {}

void TestProjectile::Tick(Time delta) {
  AutoguidedProjectile::Tick(delta);
}
