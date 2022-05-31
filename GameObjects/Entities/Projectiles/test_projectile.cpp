#include "test_projectile.h"

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

TestProjectile::TestProjectile(const VectorF& coordinates, Entity* target)
  : AutoguidedProjectile(
    coordinates,
    PixmapLoader::Pixmaps::kTestBullet,
    target,
    Entities::TestProjectile::kSpeed,
    Entities::TestProjectile::kDamage) {}

void TestProjectile::Tick(Time delta) {
  AutoguidedProjectile::Tick(delta);
}
