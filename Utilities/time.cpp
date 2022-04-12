#include "time.h"

int Time::ms() const {
  return ms_;
}

qreal Time::seconds() const {
  return ms_ / 1000.0;
}

Time::Time(int ms) : ms_(ms) {}

bool Time::operator<(const Time& rhs) const {
  return ms_ < rhs.ms_;
}

bool Time::operator>(const Time& rhs) const {
  return rhs < *this;
}

bool Time::operator<=(const Time& rhs) const {
  return !(rhs < *this);
}

bool Time::operator>=(const Time& rhs) const {
  return !(*this < rhs);
}

Time Time::operator+(const Time& rhs) const {
  return Time(ms_ + rhs.ms_);
}

Time Time::operator-(const Time& rhs) const {
  return Time(ms_ - rhs.ms_);
}

Time& Time::operator+=(const Time& rhs) {
  ms_ += rhs.ms_;
  return *this;
}

Time& Time::operator-=(const Time& rhs) {
  ms_ -= rhs.ms_;
  return *this;
}

Time& Time::operator-() {
  ms_ = -ms_;
  return *this;
}
