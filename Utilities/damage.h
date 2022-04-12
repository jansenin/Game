#pragma once

class Damage {
 public:
  explicit Damage(int damage);
  [[nodiscard]] int GetDamage() const;

 private:
  int damage_ = 0;
};
