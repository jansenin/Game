#include "tower_slot.h"
#include "GameObjects/Entities/Towers/tower.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"
#include <QGraphicsScene>

bool TowerSlot::IsTakenUp() const {
  return tower_ != nullptr;
}

void TowerSlot::TakeUpArea(Tower* tower) {
  tower_ = tower;
}

void TowerSlot::ClearArea() {
  tower_ = nullptr;
}

TowerSlot::TowerSlot(const VectorF& coordinates)
    : Entity(coordinates, PixmapLoader::Pixmaps::kTestTowerSlot), tower_(nullptr) {}

void TowerSlot::Tick(Time time) {
  Entity::Tick(time);

  if (tower_ != nullptr) {
    tower_->Tick(time);
  }
}

void TowerSlot::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  if (event->button() != Qt::MouseButton::LeftButton) {
    return TowerSlot::mousePressEvent(event);
  }
  if (!IsTakenUp()) {
    Tower* tower = new Tower(scenePos(),
                             PixmapLoader::Pixmaps::kTestTower,
                             Time(300),
                             Entities::TestTower::kAttackRange);
    scene()->addItem(tower);
    TakeUpArea(tower);
  }
  QGraphicsItem::mousePressEvent(event);
}
void TowerSlot::paint(QPainter* painter,
                      const QStyleOptionGraphicsItem* option,
                      QWidget* widget) {
  if (IsTakenUp()) return;
  Entity::paint(painter, option, widget);
}
