#pragma once

#include "GameObjects/Interface/graphics_object.h"
#include "GameObjects/Interface/tickable.h"
#include "constants.h"
#include "Utilities/animation.h"

class Explosion : public GraphicsObject, public Tickable {
 public:
  Explosion(
      const VectorF& coordinates,
      qreal radius = Explosions::kDefaultRadius,
      Damage damage = Explosions::kDefaultDamage);

  QRectF boundingRect() const override;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  void Tick(Time delta) override;

  virtual ~Explosion();

  QVariant itemChange(QGraphicsItem::GraphicsItemChange change,
                      const QVariant& value) override;

 private:
  void DamageMobs();

  Animation* animation_;
  qreal radius_;
  Damage damage_;
};
