#include "cannon_tower.h"
#include "constants.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "Controller/controller.h"
#include "GameObjects/Entities/Projectiles/cannon_projectile.h"

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
  if (current_level_ == 1) {
    if (!Controller::Instance()->HaveEnoughMoney(Costs::kTowerLevel2Upgrade)) {
      return;
    } else {
      ++current_level_;
      Controller::Instance()->LoseMoney(Costs::kTowerLevel2Upgrade);
      Tower::cooldown_ = Entities::CannonTower::kAttackCooldownLevel2;
      Tower::range_ = Entities::CannonTower::kAttackRangeLevel2;
      delete Tower::animation_;
      Tower::animation_ = new Animation(P::kCannonTowerLevel2);
      update();
      return;
    }
  }
  if (current_level_ == 2) {
    if (!Controller::Instance()->HaveEnoughMoney(Costs::kTowerLevel3Upgrade)) {
      return;
    } else {
      ++current_level_;
      Controller::Instance()->LoseMoney(Costs::kTowerLevel3Upgrade);
      Tower::cooldown_ = Entities::CannonTower::kAttackCooldownLevel3;
      Tower::range_ = Entities::CannonTower::kAttackRangeLevel3;
      delete Tower::animation_;
      Tower::animation_ = new Animation(P::kCannonTowerLevel3);
      update();
      return;
    }
  }
}

void CannonTower::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Upgrade();
}
Projectile* CannonTower::SpawnProjectile(const VectorF& coordinates,
                                         Entity* target,
                                         int level) {
  return new CannonProjectile(coordinates, target, level);
}

