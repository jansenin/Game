#pragma once

#include "QGraphicsItem"

#include "Utilities/vector_f.h"
#include "game_scene.h"
#include "game_view.h"

class GraphicsItem : public QGraphicsItem {
 public:
  GraphicsItem(QGraphicsItem* parent = nullptr);

  GameScene* scene();
  GameView* view();

  void MoveBy(const VectorF& delta);
};


