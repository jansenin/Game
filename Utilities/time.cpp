#include "time.h"

int Time::ms() const {
  return ms_;
}

int Time::seconds() const {
  return ms_ / 1000;
}
