#include "wave_manager.h"

void WaveManager::Tick(Time delta) {
  for (auto i = waves_.begin(); i != waves_.end(); ++i) {
    i->Tick(delta);
    if (i->IsEnded()) {
      waves_.erase(i);
      break;
    }
  }
}
