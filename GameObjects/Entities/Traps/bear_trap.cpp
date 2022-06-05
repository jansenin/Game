#include "bear_trap.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"
#include "Controller/controller.h"

#include <iostream>
#include <game_scene.h>
#include <vector>

QRectF BearTrap::boundingRect() const {
  return QRectF(QPointF(-15, -15), QSize(30, 30));
}

BearTrap::BearTrap(const VectorF& coordinates)
    : BearTrap(coordinates,
               new Animation(
                   PixmapLoader::Pixmaps::kBearTrapIdle,
                   50_ms)) {
  attacking_animation_ = new Animation(
      PixmapLoader::Pixmaps::kBearTrapAttacking,
      50_ms);;
  idle_animation_ = new Animation(
      PixmapLoader::Pixmaps::kBearTrapIdle,
      50_ms);
  broken_animation_ = new Animation(
      PixmapLoader::Pixmaps::kBearTrapBroken,
      50_ms);
  repairing_animation_ = new Animation(
      PixmapLoader::Pixmaps::kBearTrapBroken,
      50_ms);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setScale(2.5);
}

BearTrap::BearTrap(const VectorF& coordinates, Animation* animation)
    : Entity(coordinates, animation), cooldown_timer_(0_ms) {}

void BearTrap::Tick(Time delta) {
  cooldown_timer_.Tick(delta);
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
    if (mob->sceneBoundingRect().intersects(this->sceneBoundingRect())
        && !is_broken_) {
      mob->ApplyDamage(Entities::BearTrap::kDamage);
      animation_ = attacking_animation_;
      is_broken_ = true;
    }
  }
}

void BearTrap::paint(QPainter* painter,
                     const QStyleOptionGraphicsItem* option,
                     QWidget* widget) {
  Entity::paint(painter, option, widget);
}

void BearTrap::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  if (!cooldown_timer_.IsExpired()) {
    return;
  }
  if (!is_broken_) {
    return;
  }
  if (!Controller::Instance()->HaveEnoughMoney(Costs::kBearTrapRepairingCost)) {
    return;
  }
  if (event->button() != Qt::LeftButton) {
    return;
  }
  RepairTrap();
  cooldown_timer_.Start(Entities::BearTrap::kCooldown);
}

void BearTrap::RepairTrap() {
  is_broken_ = false;
  animation_ = repairing_animation_;
  Controller::Instance()->LoseMoney(Costs::kBearTrapRepairingCost);
  update();
}

BearTrap::~BearTrap() {
  delete idle_animation_;
  delete broken_animation_;
  delete attacking_animation_;
  delete repairing_animation_;
}


