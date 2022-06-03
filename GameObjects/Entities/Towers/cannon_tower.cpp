#include "cannon_tower.h"
#include "constants.h"
#include "Utilities/Resources/pixmap_loader.h"

using P = PixmapLoader::Pixmaps;

CannonTower::CannonTower(const VectorF& coordinates) :
    Tower(coordinates,
          P::kCannonTowerLevel1,
          Entities::CannonTower::kAttackCooldownLevel1,
          Entities::CannonTower::kAttackRangeLevel1,
          Entities::CannonTower::kMaxLevel,
          Entities::CannonTower::kPrice) {
  setScale(2);
}

void CannonTower::Upgrade() {
  Tower::Upgrade();

  ++Tower::current_level_;
  if (current_level_ == 2) {
    Tower::cooldown_ = Entities::CannonTower::kAttackCooldownLevel2;
    Tower::range_ = Entities::CannonTower::kAttackRangeLevel2;
    delete Tower::animation_;
    Tower::animation_ = new Animation(P::kCannonTowerLevel2);
    return;
  }
  if (current_level_ == 3) {
    Tower::cooldown_ = Entities::CannonTower::kAttackCooldownLevel3;
    Tower::range_ = Entities::CannonTower::kAttackRangeLevel3;
    delete Tower::animation_;
    Tower::animation_ = new Animation(P::kCannonTowerLevel3);
    return;
  }
}

void CannonTower::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Upgrade();
}
