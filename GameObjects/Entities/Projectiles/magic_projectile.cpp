#include "magic_projectile.h"

#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

using P = PixmapLoader::Pixmaps;

MagicProjectile::MagicProjectile(const VectorF& coordinates,
                                 Entity* target,
                                 int level)
    : AutoguidedProjectile(
    coordinates,
    PixmapLoader::Pixmaps::kMagicProjectileLevel1,
    target,
    Entities::MagicProjectile::kSpeed,
    Entities::MagicProjectile::kMaxSpeed,
    Entities::MagicProjectile::kAcceleration,
    Entities::MagicProjectile::kEnemyFindDistance,
    Entities::MagicProjectile::kDamageLevel1),
      destroying_animation_(new Animation(
          P::MagicProjectile::kDestroyingLevel1,
          Entities::MagicProjectile::kTimeBetweenFrames)) {
  if (level == 2) {
    animation_ = new Animation(PixmapLoader::Pixmaps::kMagicProjectileLevel2);
    damage_ = Entities::MagicProjectile::kDamageLevel2;
    destroying_animation_ = new Animation(
        P::MagicProjectile::kDestroyingLevel2,
        Entities::MagicProjectile::kTimeBetweenFrames);
  }
  if (level == 3) {
    animation_ = new Animation(PixmapLoader::Pixmaps::kMagicProjectileLevel3);
    damage_ = Entities::MagicProjectile::kDamageLevel3;
    destroying_animation_ = new Animation(
        P::MagicProjectile::kDestroyingLevel3,
        Entities::MagicProjectile::kTimeBetweenFrames);
  }
}

void MagicProjectile::Tick(Time delta) {
  Entity::Tick(delta);
  if (!is_destroying_) {
    AutoguidedProjectile::Tick(delta);
    if (is_destroying_) {
      animation_ = destroying_animation_;
      animation_->Reset();
    }
    return;
  }
  if (is_destroying_ && animation_->WasEndedDuringPreviousUpdate()) {
    animation_->SetIndex(animation_->FrameCount() - 1);
    deleteLater();
  }
}
