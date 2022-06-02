#include "hedgehog.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

using namespace Entities::Hedgehog;
using P = PixmapLoader::Pixmaps;

Hedgehog::Hedgehog(const VectorF& coordinates) :
    Mob(coordinates,
        new Animation(P::kHedgehogWalk,
                      kTimeBetweenFrames),
        kHealth,
        kSpeed), is_destroying_(false),
    walk_animation_(animation_),
    death_animation_(new Animation(P::kHedgehogDeath, kTimeBetweenFrames)) {}

void Hedgehog::ApplyDamage(Damage damage) {
  Damageable::ApplyDamage(damage);
  if (health_ <= 0 && !is_destroying_) {
    death_animation_->Reset();
    is_destroying_ = true;
    animation_ = death_animation_;
  }
}

void Hedgehog::SetRoute(Route* route) {
  Mob::SetRoute(route);
  MoveToRouteStart();
}

void Hedgehog::Tick(Time delta) {
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
