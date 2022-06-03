#pragma once

#include "QGraphicsObject"

#include "Utilities/vector_f.h"
#include "game_scene.h"
#include "game_view.h"

class GraphicsObject : public QGraphicsObject {
 public:
  explicit GraphicsObject(QGraphicsItem* parent = nullptr);

  GameScene* scene();
  GameView* view();

  void MoveBy(const VectorF& delta);
};


