#include "utility.h"

#include "GameObjects/Entities/Mobs/test_mob.h"
#include "GameObjects/Entities/Towers/TowerSlots/test_tower_slot.h"
#include "constants.h"

Mob* CreateMobFromType(QString type) {
  if (type == Entities::kTestMobId) {
    return new TestMob();
  } else {
    throw std::invalid_argument("There is no such id: " + type.toStdString());
  }
}
