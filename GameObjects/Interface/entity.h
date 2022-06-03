#pragma once

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QPixmap>
#include <QString>
#include <QObject>

#include "tickable.h"
#include "damageable.h"
#include "Utilities/vector_f.h"
#include "graphics_object.h"
#include "Utilities/animation.h"

class Entity
    : public Tickable,
      public Damageable,
      public GraphicsObject {
 public:
  Entity(
      const VectorF& coordinates,
      QPixmap* pixmap,
      int health = 0);

  Entity(
      const VectorF& coordinates,
      Animation* animation,
      int health = 0);

  QRectF boundingRect() const override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  void Tick(Time delta) override;

 protected:
  Animation* animation_;
};
