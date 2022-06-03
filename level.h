#pragma once

#include <map>
#include <vector>

#include <QJsonDocument>

#include "Utilities/vector_f.h"
#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "GameObjects/Entities/Towers/TowerSlots/tower_slot.h"
#include "Utilities/route.h"
#include "Utilities/wave.h"

class Level {
 public:
  explicit Level(int level_number);

  void AddObjectsToScene(GameScene* scene);
  void Tick(Time delta);

  [[nodiscard]] const std::vector<Route*>& GetRoutes() const;
  [[nodiscard]] const std::vector<Wave*>& GetWaves();
  [[nodiscard]] int GetLevelNumber() const;
  [[nodiscard]] int GetStartMoney() const;
  bool IsTimeForGrow();

 private:
  class SpawnEntry {
   public:
    explicit SpawnEntry(QJsonObject* spawn_root_object);

    [[nodiscard]] Time GetEntryEndTime() const;
    void AddMobsToWave(
        std::map<Mob*, Time>* mobs,
        const std::vector<Route*>& routes) const;

   private:
    Time start_time_;
    QString mob_type_;
    int count_;
    Time entry_duration_;
    int route_index_;
  };

  std::vector<TowerSlot*> tower_slots_{};
  std::vector<Route*> routes_{};
  std::vector<Wave*> waves_{};
  std::vector<Time> timers_for_grow_{};
  int level_number_;
  int startMoney_;
};
