#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <vector>
#include <unordered_set>

#include "../BasicObjects/Interface/tickable.h"
#include "../BasicObjects/Entities/Mobs/Basis/mob.h"
#include "../BasicObjects/Entities/Towers/tower.h"
#include "../BasicObjects/Entities/Towers/TowerSlots/tower_slot.h"

class GameField : public Tickable {
 public:
  GameField();
  GameField(
      const std::vector<Mob*>& mobs,
      const std::vector<TowerSlot*>& tower_slots);
  void AddMob(Mob* mob);
  void AddTowerSlot(TowerSlot* tower_slot);
  const std::unordered_set<TowerSlot*>& GetTowerSlots();
  const std::unordered_set<Mob*>& GetMobs();
 private:
  std::unordered_set<Mob*> mobs_{0};
  std::unordered_set<TowerSlot*> tower_slots_{0};
  // std::vector<Projectiles> projectiles_;
};

#endif //GAME_FIELD_H
