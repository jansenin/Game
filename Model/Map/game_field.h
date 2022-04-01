#ifndef MODEL_MAP_GAME_FIELD_H_
#define MODEL_MAP_GAME_FIELD_H_

#include <vector>
#include <unordered_set>

#include "../BasicObjects/Interface/tickable.h"
#include "../BasicObjects/Entities/Mobs/Basis/mob.h"
#include "../BasicObjects/Entities/Towers/tower.h"
#include "../BasicObjects/Entities/Towers/TowerSlots/tower_slot.h"
#include "../../View/game_view.h"

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
  void Tick(Time time) override;

 private:
  std::unordered_set<Mob*> mobs_;
  std::unordered_set<TowerSlot*> tower_slots_;
  GameView* view_;
  // std::vector<Projectiles> projectiles_;
};

#endif  // MODEL_MAP_GAME_FIELD_H_
