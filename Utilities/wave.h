#pragma once
#include "GameObjects/BasicObjects/Interface/tickable.h"
#include "GameObjects/BasicObjects/Entities/Mobs/Basis/mob.h"
#include <map>
#include <utility>

class Wave : public Tickable {
 public:
  explicit Wave(Time ms, std::map<Mob*, Time>&&  mobs) : time_to_start_(ms),
                                        mobs_time_to_spawn_(std::move(mobs)) {}
  void Tick(Time delta) override;
  void RemoveMobFromWave(Mob*);
  [[nodiscard]] bool IsStarted() const;
  [[nodiscard]] bool IsEnded() const;

 private:
  Time time_to_start_;
  std::map<Mob*, Time> mobs_time_to_spawn_;
};

