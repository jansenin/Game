#include "linear_test_projectile.h"

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

LinearTestProjectile::LinearTestProjectile(
    const VectorF& coordinates, Entity* target)
    : LinearAutoguidedProjectile(
    coordinates,
    PixmapLoader::Pixmaps::kTestBullet,
    target,
    500,
    Entities::TestProjectile::kDamage) {}

void LinearTestProjectile::Tick(Time delta) {
  LinearAutoguidedProjectile::Tick(delta);
}
