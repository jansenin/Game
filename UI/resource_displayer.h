#pragma once

#include "textured_box.h"
#include "linear_layout.h"
#include "pixmap_object.h"

class ResourcesDisplayer : public TexturedBox {
 public:
  ResourcesDisplayer();

  void SetMoney(int money);
  void SetHp(int hp);

 private:
  LinearLayout* resources_layout_;
  QGraphicsTextItem* money_item_;
  QGraphicsTextItem* hp_item_;
  PixmapObject* money_icon_;
  PixmapObject* hp_icon_;
};
