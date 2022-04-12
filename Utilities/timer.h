#pragma once

#include "time.h"

class Timer {
 public:
  explicit Timer(const Time& remaining_time);

  void Tick(const Time& delta_time);
  Time RemainingTime();
  bool IsExpired();
  void Start(const Time& remaining_time);
  Time HowMuchExpired();

 private:
  Time remaining_time_;
};
