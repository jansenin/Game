#pragma once

#include <QPixmap>

#include "GameObjects/Interface/entity.h"
#include "Utilities/vector_f.h"
#include "Utilities/route.h"

class Mob : public Entity {
 public:
  Mob(const VectorF& coordinates,
      QPixmap* pixmap,
      int health,
      int damage_to_base,
      qreal speed);

  Mob(const VectorF& coordinates,
      Animation* animation,
      int health,
      int damage_to_base,
      qreal speed);

  virtual void SetRoute(Route* route);
  void MoveToRouteStart();

  [[nodiscard]] qreal GetSpeed() const;
  void SetSpeed(qreal speed);

  void Tick(Time delta) override;

  QRectF boundingRect() const override;

  virtual ~Mob();

 protected:
  Route* route_{nullptr};
  qreal speed_;
  bool dealed_damage_to_base_;
  int damage_to_base_;
};
