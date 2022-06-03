#include "coin.h"
#include "Utilities/Resources/pixmap_loader.h"
//#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "constants.h"


#include <iostream>
#include <game_scene.h>

Coin::Coin(const VectorF& coordinates, QPixmap* pixmap)
    : Coin(coordinates, new Animation(PixmapLoader::Pixmaps::kCoinIdle, 50_ms)) {
  idle_animation_ = new Animation(PixmapLoader::Pixmaps::kCoinIdle, 50_ms);
  collecting_route_ = nullptr;
  speed_ = 300;
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setScale(2.5);
}

Coin::Coin(const VectorF& coordinates, Animation* animation)
    : Entity(coordinates, animation) {}

void Coin::Tick(Time delta) {
  if (animation_->WasEndedDuringPreviousUpdate()) {
    animation_ = idle_animation_;
  }
  if (collecting_route_ != nullptr) {
    collecting_route_->Move(this, delta.ms() * speed_);
  }
  Entity::Tick(delta);
}

void Coin::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
  Entity::paint(painter, option, widget);
}

void Coin::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  scene()->IncCoinsCount();
  update();
  SetRoute();
  delete this;
  // add money

}


Coin::~Coin() {
  delete idle_animation_;
//  scene()->DecCoinsCount();
}

void Coin::SetRoute() {
  std::vector<VectorF> points;
  points.emplace_back(this->pos().x(), this->pos().y());
  points.emplace_back(50, 50);
  collecting_route_ = new Route(points);
  collecting_route_->AddEntity(this);
}

