#include "magic_tower.h"
#include "constants.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "Controller/controller.h"
#include "GameObjects/Entities/Projectiles/magic_projectile.h"

using P = PixmapLoader::Pixmaps;

MagicTower::MagicTower(const VectorF& coordinates) :
    Tower(coordinates,
          P::kMagicTowerLevel1,
          Entities::MagicTower::kAttackCooldownLevel1,
          Entities::MagicTower::kAttackRangeLevel1,
          Entities::MagicTower::kMaxLevel,
          Entities::MagicTower::kPrice) {
  Controller::Instance()->LoseMoney(Costs::kMagicTowerCost);
}

void MagicTower::Upgrade() {
  Tower::Upgrade();
  if (current_level_ == 1) {
    if (!Controller::Instance()->HaveEnoughMoney(Costs::kTowerLevel2Upgrade)) {
      return;
    } else {
      ++current_level_;
      Controller::Instance()->LoseMoney(Costs::kTowerLevel2Upgrade);
      Tower::cooldown_ = Entities::MagicTower::kAttackCooldownLevel2;
      Tower::range_ = Entities::MagicTower::kAttackRangeLevel2;
      delete Tower::animation_;
      Tower::animation_ = new Animation(P::kMagicTowerLevel2);
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
      Tower::cooldown_ = Entities::MagicTower::kAttackCooldownLevel3;
      Tower::range_ = Entities::MagicTower::kAttackRangeLevel3;
      delete Tower::animation_;
      Tower::animation_ = new Animation(P::kMagicTowerLevel3);
      update();
      return;
    }
  }
}

void MagicTower::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Upgrade();
}

Projectile* MagicTower::SpawnProjectile(const VectorF& coordinates,
                                        Entity* target,
                                        int level) {
  return new MagicProjectile(coordinates, target, level);
}

