#ifndef UTILITIES_DAMAGE_H_
#define UTILITIES_DAMAGE_H_

class Damage {
 public:
  explicit Damage(int damage);
  [[nodiscard]] int GetDamage() const;

 private:
  int damage_ = 0;
};

#endif  // UTILITIES_DAMAGE_H_
