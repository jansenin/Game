#include "bomb.h"
#include "Utilities/Resources/pixmap_loader.h"

#include "constants.h"


#include <iostream>
#include <game_scene.h>

QRectF Bomb::boundingRect() const {
  return QRectF(QPointF(-15,-15), QSize(30, 30));
}

Bomb::Bomb(const VectorF& coordinates, QPixmap* pixmap)
    : Bomb(coordinates, new Animation(PixmapLoader::Pixmaps::kBombIdle, 50_ms)) {
  idle_animation_ = new Animation(PixmapLoader::Pixmaps::kBombIdle, 50_ms);
  explosion_animation_ = new Animation(PixmapLoader::Pixmaps::kBombExplosion, 50_ms);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setScale(2.5);
}

Bomb::Bomb(const VectorF& coordinates, Animation* animation)
    : Entity(coordinates, animation) {}

void Bomb::Tick(Time delta) {
  if (animation_->WasEndedDuringPreviousUpdate()) {
    if (activated_) {
      animation_ = explosion_animation_;
    }
  }

  Entity::Tick(delta);
  if (activated_ && animation_->WasEndedDuringPreviousUpdate()) {
    std::vector<Mob*> mobs = scene()->Mobs();
    for (auto mob : mobs) {
      if (mob->sceneBoundingRect().intersects(this->sceneBoundingRect())) {
        mob->ApplyDamage(Damage(mob->GetHealth()));
        animation_ = explosion_animation_;
      }
    }
    delete this;
  }
}

void Bomb::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
  Entity::paint(painter, option, widget);
}

void Bomb::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  if (event->button() != Qt::LeftButton) {
    return;
  }
  Explode();
}


Bomb::~Bomb() {
  delete idle_animation_;
  delete explosion_animation_;
}

void Bomb::Explode() {
  activated_ = true;
}

