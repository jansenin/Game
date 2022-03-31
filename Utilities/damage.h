#ifndef DAMAGE_H
#define DAMAGE_H

class Damage {
 public:
  explicit Damage(int damage);
  [[nodiscard]] int GetDamage() const;
 private:
  int damage_ = 0;
};

#endif //DAMAGE_H
