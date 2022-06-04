#include "wave.h"

#include "Controller/controller.h"

void Wave::RemoveMobFromWave(Mob* mob) {
  mobs_time_to_spawn_.erase(mob);
}

void Wave::Tick(Time delta) {
  if (IsStarted()) {
    for (auto i = mobs_time_to_spawn_.begin();
         i != mobs_time_to_spawn_.end();) {
      i->second -= delta;
      if (i->second.ms() <= 0) {
        Controller::Instance()->GetScene()->addItem(i->first);
        Mob* mob_to_remove = i->first;
        i++;
        RemoveMobFromWave(mob_to_remove);
      } else {
        i++;
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
