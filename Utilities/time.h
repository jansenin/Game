//
// Created by artsa on 22.03.2022.
//

#ifndef TIME_H
#define TIME_H

class Time {
 public:
  [[nodiscard]] int ms() const;
  [[nodiscard]] int seconds() const;
 private:
  int ms_;
};

#endif //TIME_H
