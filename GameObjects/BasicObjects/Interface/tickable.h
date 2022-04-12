#pragma once

#include "Utilities/time.h"

class Tickable {
 public:
  virtual void Tick(Time delta) = 0;
};
