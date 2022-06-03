#include "cannon_tower.h"
#include "constants.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "Controller/controller.h"

using P = PixmapLoader::Pixmaps;

CannonTower::CannonTower(const VectorF& coordinates) :
    Tower(coordinates,
          P::kCannonTowerLevel1,
          Entities::CannonTower::kAttackCooldownLevel1,
          Entities::CannonTower::kAttackRangeLevel1,
          Entities::CannonTower::kMaxLevel,
          Entities::CannonTower::kPrice) {
  setScale(2);
  Controller::Instance()->LoseMoney(Costs::kCannonTowerCost);
}

void CannonTower::Upgrade() {
  Tower::Upgrade();
  ++Tower::current_level_;
  if (current_level_ == 2) {
    if (!Controller::Instance()->HaveEnoughMoney(Costs::kTowerLevel2Upgrade)) {
      return;
    }
    Controller::Instance()->LoseMoney(Costs::kTowerLevel2Upgrade);
    Tower::cooldown_ = Entities::CannonTower::kAttackCooldownLevel2;
    Tower::range_ = Entities::CannonTower::kAttackRangeLevel2;
    delete Tower::animation_;
    Tower::animation_ = new Animation(P::kCannonTowerLevel2);
    update();
    return;
  }
  if (current_level_ == 3) {
    if (!Controller::Instance()->HaveEnoughMoney(Costs::kTowerLevel3Upgrade)) {
      return;
    }
    Controller::Instance()->LoseMoney(Costs::kTowerLevel3Upgrade);
    Tower::cooldown_ = Entities::CannonTower::kAttackCooldownLevel3;
    Tower::range_ = Entities::CannonTower::kAttackRangeLevel3;
    delete Tower::animation_;
    Tower::animation_ = new Animation(P::kCannonTowerLevel3);
    update();
    return;
  }
}

void CannonTower::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Upgrade();
}

