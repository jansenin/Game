#pragma once

#include <QPixmap>

#include "GameObjects/BasicObjects/Interface/entity.h"
#include "Utilities/vector_f.h"
#include "Utilities/route.h"

class Mob : public Entity {
 public:
  Mob(const VectorF& coordinates,
      QPixmap* pixmap,
      int health,
      qreal speed = 0);

  Mob(const VectorF& coordinates,
      Animation* animation,
      int health,
      qreal speed = 0);

  virtual void SetRoute(Route* route);
  void MoveToRouteStart();

  [[nodiscard]] qreal GetSpeed() const;
  void SetSpeed(qreal speed);

 protected:
  Route* route_{nullptr};
  qreal speed_;
};
