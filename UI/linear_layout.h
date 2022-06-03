#pragma once

#include <vector>

#include <QGraphicsItem>
#include <QGraphicsObject>



// positions items one after another, centered by y
class LinearLayout : public QGraphicsObject {
 public:
  enum class Type { Horizontal, Vertical };

  explicit LinearLayout(QGraphicsItem* parent = nullptr);

  QRectF boundingRect() const override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

  void AddItem(QGraphicsObject* item);
  void RemoveItem(QGraphicsObject* item);
  bool HasItem(QGraphicsObject* item);

  qreal Spacing() const;
  void SetSpacing(qreal spacing);

  Type Type() const;
  void SetType(enum Type type);

  void RecalculatePositions();

 protected:
  void OnItemDestroyed(QObject* item);
  void ConnectItem(QGraphicsObject* item);
  void DisconnectItem(QGraphicsObject* item);

  std::vector<QGraphicsObject*> items_;
  qreal spacing_;
  enum Type type_;
};
