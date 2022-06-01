#include <QString>

#include "GameObjects/BasicObjects/Entities/Mobs/test_mob.h"
#include "GameObjects/BasicObjects/Entities/Towers/TowerSlots/test_tower_slot.h"
#include "constants.h"
#include "utility.h"

Mob* CreateMobFromType(QString type) {
  if (type == Entities::kTestMobId) {
    return new TestMob();
  } else {
    throw std::invalid_argument("There is no such id: " + type.toStdString());
  }
}
