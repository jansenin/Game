#include "timer.h"

Timer::Timer(const Time& remaining_time) : remaining_time_(remaining_time) {}

void Timer::Tick(const Time& delta_time) {
  remaining_time_ -= delta_time;
}

Time Timer::RemainingTime() {
  return remaining_time_;
}

bool Timer::IsExpired() {
  return remaining_time_ <= Time(0);
}

void Timer::Start(const Time& remaining_time) {
  remaining_time_ = remaining_time;
}

Time Timer::HowMuchExpired() {
  return -remaining_time_;
}
