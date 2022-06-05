#include "tower_slot.h"
#include "GameObjects/Entities/Towers/tower.h"
#include "GameObjects/Entities/Towers/magic_tower.h"
#include "GameObjects/Entities/Towers/cannon_tower.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"
#include "Controller/controller.h"
#include <QGraphicsScene>

bool TowerSlot::IsTakenUp() const {
  return tower_ != nullptr;
}

void TowerSlot::TakeUpArea(Tower* tower) {
  tower_ = tower;
  scene()->IncMagicTowersCount();
}

void TowerSlot::ClearArea() {
  tower_ = nullptr;
}

TowerSlot::TowerSlot(const VectorF& coordinates)
    : Entity(coordinates, PixmapLoader::Pixmaps::kTowerSlot), tower_(nullptr) {
  setScale(0.45);
}

void TowerSlot::Tick(Time time) {
  Entity::Tick(time);

  if (tower_ != nullptr) {
    tower_->Tick(time);
  }
}

void TowerSlot::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  if (event->button() == Qt::MouseButton::LeftButton) {
    if (!IsTakenUp()) {
      if (!Controller::Instance()->HaveEnoughMoney(Costs::kMagicTowerCost)) {
        return;
      }
      MagicTower* tower = new MagicTower(scenePos());
      scene()->addItem(tower);
      TakeUpArea(tower);
    }
    QGraphicsItem::mousePressEvent(event);
    return;
  }
  if (event->button() == Qt::MouseButton::RightButton) {
    if (!IsTakenUp()) {
      if (!Controller::Instance()->HaveEnoughMoney(Costs::kCannonTowerCost)) {
        return;
      }
      CannonTower* tower = new CannonTower(scenePos());
      scene()->addItem(tower);
      TakeUpArea(tower);
    }
    QGraphicsItem::mousePressEvent(event);
    return;
  }
}
  void TowerSlot::paint(QPainter* painter,
                        const QStyleOptionGraphicsItem* option,
                        QWidget* widget) {
    if (IsTakenUp()) return;
    Entity::paint(painter, option, widget);
  }
