#pragma once

#include "GameObjects/BasicObjects/Interface/entity.h"

#include <QPixmap>

#include "Utilities/vector_f.h"

class Mob : public Entity {
 public:
  Mob(const VectorF& coordinates, QPixmap* pixmap, int health, qreal speed = 1);
  qreal GetSpeed() const;
  void SetSpeed(qreal speed);

 private:
  qreal speed_;
};
