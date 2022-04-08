#ifndef MODEL_BASICOBJECTS_INTERFACE_ENTITY_H_
#define MODEL_BASICOBJECTS_INTERFACE_ENTITY_H_

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QPixmap>
#include <QString>
#include <QObject>

#include "tickable.h"
#include "damagable.h"

class Entity
    : public QObject,
      public Tickable,
      public Damageable,
      public QGraphicsItem {
  Q_OBJECT
 public:
  Entity(
      QPointF coordinates,
      QString path_to_pixmap,
      int health = 0);

  [[nodiscard]] QRectF boundingRect() const override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

  void MoveBy(QPointF delta);

 protected:
  QPixmap* pixmap;
};

#endif  // MODEL_BASICOBJECTS_INTERFACE_ENTITY_H_
