#ifndef UTILITIES_TIME_H_
#define UTILITIES_TIME_H_

class Time {
 public:
  [[nodiscard]] int ms() const;
  [[nodiscard]] int seconds() const;

 private:
  int ms_;
};

#endif  // UTILITIES_TIME_H_
