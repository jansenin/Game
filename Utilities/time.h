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
  Time operator*(int rhs) const;

  Time& operator+=(const Time& rhs);
  Time& operator-=(const Time& rhs);
  Time& operator*=(int rhs);
  friend Time operator*(int lhs, const Time& rhs);

  Time& operator-();

 private:
  int ms_;
};

Time operator*(int lhs, const Time& rhs);

// cpplint говорит, что unsigned long long int(Тип из си) нужно поменять на
// int16/int32/int64...(тип из C++), но в документации к пользовательским
// литералам сказано, что в них могут использоваться только определённые
// типы(и записи unsigned long long int в C++ я не нашёл, а это единственный
// целочисленный тип, который можно использовать для литерала)
Time operator "" _ms(unsigned long long int ms); // NOLINT
