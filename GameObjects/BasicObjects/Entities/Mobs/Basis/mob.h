#pragma once

#include "GameObjects/BasicObjects/Interface/entity.h"
#include "Utilities/vector_f.h"
#include "Utilities/route.h"

#include <QPixmap>

class Mob : public Entity {
 public:
  Mob(const VectorF& coordinates,
      QPixmap* pixmap,
      int health,
      Route&& route,
      qreal speed = 20);
  [[nodiscard]] qreal GetSpeed() const;
  void SetSpeed(qreal speed);

 protected:
  Route route_;
  qreal speed_;
};
