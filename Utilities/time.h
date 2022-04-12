#pragma once

#include <QtGlobal>

class Time {
 public:
  explicit Time(int ms);

  [[nodiscard]] int ms() const;
  [[nodiscard]] qreal seconds() const;

  bool operator<(const Time& rhs) const;
  bool operator>(const Time& rhs) const;
  bool operator<=(const Time& rhs) const;
  bool operator>=(const Time& rhs) const;

  Time operator+(const Time& rhs) const;
  // there is no check for negative time
  Time operator-(const Time& rhs) const;

  Time& operator+=(const Time& rhs);
  Time& operator-=(const Time& rhs);

  Time& operator-();

 private:
  int ms_;
};
