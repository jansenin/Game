#pragma once

#include <QPixmap>

#include "Basis/mob.h"
#include "Utilities/vector_f.h"

class TestMob : public Mob {
 public:
  explicit TestMob(const VectorF& coordinates = VectorF{0, 0});

  void Tick(Time delta) override;

  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

 protected:
  void keyPressEvent(QKeyEvent* event) override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};
