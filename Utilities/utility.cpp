#include <QString>

#include "GameObjects/Entities/Mobs/test_mob.h"
#include "GameObjects/Entities/Towers/TowerSlots/test_tower_slot.h"
#include "GameObjects/Entities/Mobs/skeleton.h"
#include "GameObjects/Entities/Mobs/cobra.h"
#include "GameObjects/Entities/Mobs/hedgehog.h"
#include "GameObjects/Entities/Mobs/dwarf.h"
#include "constants.h"
#include "utility.h"

Mob* CreateMobFromType(QString type) {
  if (type == Entities::kTestMobId) {
    return new TestMob();
  }
  if (type == Entities::kSkeletonId) {
    return new Skeleton();
  }
  if (type == Entities::kCobraId) {
    return new Cobra();
  }
  if (type == Entities::kHedgehogId) {
    return new Hedgehog();
  }
  if (type == Entities::kDwarfId) {
    return new Dwarf();
  }
    throw std::invalid_argument("There is no such id: " + type.toStdString());
  }
