#pragma once

#include <QPixmap>

#include "Basis/mob.h"
#include "Utilities/vector_f.h"

class TestMob : public Mob {
 public:
  explicit TestMob(const VectorF& coordinates = VectorF{0, 0});

  void Tick(Time delta) override;
  void ApplyDamage(Damage damage) override;
  void SetRoute(Route* route) override;

  ~TestMob() override;

 protected:
  void keyPressEvent(QKeyEvent* event) override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

  bool is_destroying_;
  bool is_creating_;
  Animation* idle_animation_;
  Animation* disappearing_animation_;
  Animation* appearing_animation_;
};
