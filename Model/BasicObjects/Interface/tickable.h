#ifndef TICKABLE_H
#define TICKABLE_H

#include "../../../Utilities/time.h"

class Tickable {
 public:
  virtual void Tick(Time delta) = 0;
};

#endif //TICKABLE_H
