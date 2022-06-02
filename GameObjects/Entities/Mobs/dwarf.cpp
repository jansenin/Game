#include "dwarf.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

namespace D = Entities::Dwarf;
using P = PixmapLoader::Pixmaps;

Dwarf::Dwarf(const VectorF& coordinates) :
    Mob(coordinates,
        new Animation(P::Dwarf::kWalk,
                      D::kTimeBetweenFrames),
        D::kHealth,
        D::kDamageToBase,
        D::kSpeed), is_destroying_(false),
    walk_animation_(animation_),
    death_animation_(new Animation(P::Dwarf::kDeath, D::kTimeBetweenFrames)) {
  setScale(3);
}

void Dwarf::ApplyDamage(Damage damage) {
  Damageable::ApplyDamage(damage);
  if (health_ <= 0 && !is_destroying_) {
    death_animation_->Reset();
    is_destroying_ = true;
    animation_ = death_animation_;
  }
}

void Dwarf::SetRoute(Route* route) {
  Mob::SetRoute(route);
  MoveToRouteStart();
}

void Dwarf::Tick(Time delta) {
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

QRectF Dwarf::boundingRect() const {
  return Mob::boundingRect().translated(0, 5);
}
