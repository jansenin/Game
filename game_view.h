#pragma once

#include <QGraphicsView>

class GameView : public QGraphicsView {
 public:
  explicit GameView(QGraphicsScene* scene, QWidget* parent = nullptr);
};
