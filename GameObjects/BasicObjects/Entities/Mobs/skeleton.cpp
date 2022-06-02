#include "skeleton.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

namespace S = Entities::Skeleton;
using P = PixmapLoader::Pixmaps;

Skeleton::Skeleton(const VectorF& coordinates) :
    Mob(coordinates,
        new Animation(P::kSkeletonWalk,
                      S::kTimeBetweenFrames),
        S::kHealth,
        S::kSpeed), is_destroying_(false),
    walk_animation_(animation_),
    death_animation_(new Animation(P::kSkeletonDeath, S::kTimeBetweenFrames)) {}

void Skeleton::ApplyDamage(Damage damage) {
  Damageable::ApplyDamage(damage);
  if (health_ <= 0 && !is_destroying_) {
    death_animation_->Reset();
    is_destroying_ = true;
    animation_ = death_animation_;
  }
}

void Skeleton::SetRoute(Route* route) {
  Mob::SetRoute(route);
  MoveToRouteStart();
}

void Skeleton::Tick(Time delta) {
  Mob::Tick(delta);
  if (is_destroying_ && animation_->WasEndedDuringPreviousUpdate()) {
    animation_->SetIndex(animation_->FrameCount() - 1);
    deleteLater();
  }
  if (route_ != nullptr) {
    if (!is_destroying_ && !route_->isEnd(this)) {
      route_->Move(this, speed_ * delta.seconds());
    }
  }
}
