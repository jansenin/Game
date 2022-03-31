#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

#include "tickable.h"
#include "damagable.h"

class Entity
    : public Tickable,
      public Damagable,
      public QGraphicsItem {
 public:
  Entity(QPointF coordinates,
         int health, qreal width, qreal height);

  [[nodiscard]] float GetHeight() const;
  [[nodiscard]] float GetWidth() const;

  QRectF boundingRect() const override;

 protected:
  float height_;
  float width_;
};

#endif //ENTITY_H
