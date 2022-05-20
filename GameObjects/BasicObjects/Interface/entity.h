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
#include "GameObjects/BasicObjects/Interface/graphics_item.h"
#include "Utilities/animation.h"

class Entity
    : public QObject,
      public Tickable,
      public Damageable,
      public GraphicsItem {
  Q_OBJECT
 public:
  Entity(
      const VectorF& coordinates,
      QPixmap* pixmap,
      int health = 0);

  Entity(
      const VectorF& coordinates,
      Animation* animation,
      int health = 0);

  [[nodiscard]] QRectF boundingRect() const override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  void Tick(Time delta) override;

 protected:
  Animation* animation_;
};
