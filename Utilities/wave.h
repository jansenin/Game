#pragma once

#include <map>
#include <utility>

#include "GameObjects/Interface/tickable.h"
#include "GameObjects/Entities/Mobs/Basis/mob.h"

class Wave {
 public:
  explicit Wave(Time time_to_start, std::map<Mob*, Time>&&  mobs)
      : time_to_start_(time_to_start), mobs_time_to_spawn_(std::move(mobs)) {}

  void Tick(Time delta);
  // TODO(jansenin): we need to use it somewhere
  void RemoveMobFromWave(Mob*);
  [[nodiscard]] bool IsStarted() const;
  [[nodiscard]] bool IsEnded() const;

 private:
  Time time_to_start_;
  std::map<Mob*, Time> mobs_time_to_spawn_;
};

