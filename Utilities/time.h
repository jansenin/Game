#ifndef UTILITIES_TIME_H_
#define UTILITIES_TIME_H_

#include <QtGlobal>

class Time {
 public:
  explicit Time(int ms);

  [[nodiscard]] int ms() const;
  [[nodiscard]] qreal seconds() const;

 private:
  int ms_;
};

#endif  // UTILITIES_TIME_H_
