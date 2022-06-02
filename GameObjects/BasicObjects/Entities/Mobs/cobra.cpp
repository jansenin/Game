#include "cobra.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

using namespace Entities::Cobra;
using P = PixmapLoader::Pixmaps;

Cobra::Cobra(const VectorF& coordinates) :
    Mob(coordinates,
        new Animation(P::kCobraWalk,
                      kTimeBetweenFrames),
        kHealth,
        kSpeed), is_destroying_(false),
    walk_animation_(animation_),
    death_animation_(new Animation(P::kCobraDeath, kTimeBetweenFrames)) {}

void Cobra::ApplyDamage(Damage damage) {
  Damageable::ApplyDamage(damage);
  if (health_ <= 0 && !is_destroying_) {
    death_animation_->Reset();
    is_destroying_ = true;
    animation_ = death_animation_;
  }
}

void Cobra::SetRoute(Route* route) {
  Mob::SetRoute(route);
  MoveToRouteStart();
}

void Cobra::Tick(Time delta) {
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
