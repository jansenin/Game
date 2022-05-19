#include "wave.h"

void Wave::RemoveMobFromWave(Mob* mob) {
  mobs_time_to_spawn_.erase(mob);
}

void Wave::Tick(Time delta) {
  if (IsStarted()) {
    for (auto i : mobs_time_to_spawn_) {
      i.second -= delta;
      if (i.second.ms() <= 0) {
        // TODO(parfen01): move mob to map before removing from wave
        RemoveMobFromWave(i.first);
      }
    }
  } else {
    time_to_start_ -= delta;
  }
}

bool Wave::IsStarted() const {
  return time_to_start_.ms() <= 0;
}
bool Wave::IsEnded() const {
  return mobs_time_to_spawn_.empty();
}
