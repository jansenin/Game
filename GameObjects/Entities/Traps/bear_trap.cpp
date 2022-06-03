#include "bear_trap.h"
#include "Utilities/Resources/pixmap_loader.h"
//#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "constants.h"


#include <iostream>
#include <game_scene.h>

QRectF BearTrap::boundingRect() const {
  return QRectF(QPointF(-15,-15), QSize(30, 30));
}

BearTrap::BearTrap(const VectorF& coordinates, QPixmap* pixmap)
    : BearTrap(coordinates, new Animation(PixmapLoader::Pixmaps::kBearTrapIdle, 50_ms)) {
  attacking_animation_ = new Animation(PixmapLoader::Pixmaps::kBearTrapAttacking, 50_ms);;
  idle_animation_ = new Animation(PixmapLoader::Pixmaps::kBearTrapIdle, 50_ms);
  broken_animation_ = new Animation(PixmapLoader::Pixmaps::kBearTrapBroken, 50_ms);
  repairing_animation_ = new Animation(PixmapLoader::Pixmaps::kBearTrapBroken, 50_ms);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setScale(2.5);
}

BearTrap::BearTrap(const VectorF& coordinates, Animation* animation)
    : Entity(coordinates, animation) {}

void BearTrap::Tick(Time delta) {
  if (animation_->WasEndedDuringPreviousUpdate()) {
    if (is_broken_) {
      animation_ = repairing_animation_;
    } else {
      animation_ = idle_animation_;
    }
  }
  Entity::Tick(delta);
  std::vector<Mob*> mobs = scene()->Mobs();
  for (auto mob : mobs) {
    if (mob->sceneBoundingRect().intersects(this->sceneBoundingRect()) && !is_broken_) {
      mob->ApplyDamage(Damage(mob->GetHealth()));
      animation_ = attacking_animation_;
      is_broken_ = true;
    }
  }
}

void BearTrap::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
  Entity::paint(painter, option, widget);
}

void BearTrap::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  if (event->button() != Qt::LeftButton) {
    return;
  }
  RepairTrap();
}

void BearTrap::RepairTrap() {
  is_broken_ = false;
  animation_ = repairing_animation_;
  update();
}

BearTrap::~BearTrap() {
  delete idle_animation_;
  delete broken_animation_;
  delete attacking_animation_;
  delete repairing_animation_;
}


