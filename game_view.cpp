#include "game_view.h"

GameView::GameView(QGraphicsScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent) {
  scale(1/devicePixelRatio(), 1/devicePixelRatio());
  setInteractive(true);
  setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
  setRenderHint(QPainter::RenderHint::Antialiasing);
  setOptimizationFlag(
      QGraphicsView::OptimizationFlag::DontSavePainterState);
  setViewportUpdateMode(
      QGraphicsView::ViewportUpdateMode::FullViewportUpdate);

  setViewportMargins(0, 0, 0, 0);
  setContentsMargins(0, 0, 0, 0);
  setFrameStyle(QFrame::NoFrame);

  centerOn(0, 0);
}
