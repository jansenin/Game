#include "time.h"

int Time::ms() const {
  return ms_;
}

qreal Time::seconds() const {
  return ms_ / 1000.0;
}

Time::Time(int ms) : ms_(ms) {}
