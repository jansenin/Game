#include <QString>

#include "GameObjects/BasicObjects/Entities/Mobs/test_mob.h"
#include "GameObjects/BasicObjects/Entities/Towers/TowerSlots/test_tower_slot.h"
#include "GameObjects/BasicObjects/Entities/Mobs/skeleton.h"
#include "GameObjects/BasicObjects/Entities/Mobs/cobra.h"
#include "GameObjects/BasicObjects/Entities/Mobs/hedgehog.h"
#include "GameObjects/BasicObjects/Entities/Mobs/dwarf.h"
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
