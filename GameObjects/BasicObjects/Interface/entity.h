#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QPixmap>
#include <QString>
#include <QObject>

#include "tickable.h"
#include "damageable.h"
#include "Utilities/vector_f.h"

class Entity
    : public QObject,
      public Tickable,
      public Damageable,
      public QGraphicsItem {
  Q_OBJECT
 public:
  Entity(
      const VectorF& coordinates,
      QPixmap* pixmap,
      int health = 0);

  [[nodiscard]] QRectF boundingRect() const override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

  void MoveBy(const VectorF& delta);

 protected:
  QPixmap* pixmap;
};
