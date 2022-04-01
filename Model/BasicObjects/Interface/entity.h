#ifndef MODEL_BASICOBJECTS_INTERFACE_ENTITY_H_
#define MODEL_BASICOBJECTS_INTERFACE_ENTITY_H_

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

#include "tickable.h"
#include "damagable.h"

class Entity
    : public Tickable,
      public Damageable,
      public QGraphicsItem {
 public:
  Entity(QPointF coordinates,
         int health, qreal width, qreal height);

  [[nodiscard]] float GetHeight() const;
  [[nodiscard]] float GetWidth() const;

  [[nodiscard]] QRectF boundingRect() const override;

 protected:
  float height_;
  float width_;
};

#endif  // MODEL_BASICOBJECTS_INTERFACE_ENTITY_H_
