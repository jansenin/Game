#include "cannon_projectile.h"

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

CannonProjectile::CannonProjectile(
    const VectorF& coordinates, Entity* target, int level)
    : LinearAutoguidedProjectile(
    coordinates,
    PixmapLoader::Pixmaps::kCannonProjectileLevel1,
    target,
    Entities::CannonProjectile::kSpeed,
    Entities::CannonProjectile::kDamageLevel1) {
  if (level == 2) {
    animation_ = new Animation(PixmapLoader::Pixmaps::kCannonProjectileLevel2);
    damage_ = Entities::CannonProjectile::kDamageLevel2;
  }
  if (level == 3) {
    animation_ = new Animation(PixmapLoader::Pixmaps::kCannonProjectileLevel3);
    damage_ = Entities::CannonProjectile::kDamageLevel3;
  }
}

void CannonProjectile::Tick(Time delta) {
  LinearAutoguidedProjectile::Tick(delta);
}
