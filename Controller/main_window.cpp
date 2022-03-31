#include "main_window.h"

#include <iostream>

#include <QVBoxLayout>
#include <QTimer>

#include "../Model/BasicObjects/Entities/Mobs/mob_test.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    scene_(new QGraphicsScene(-1920/2,-1080/2,1920,1080)),
    view_(new QGraphicsView(scene_)) {
  setCentralWidget(view_);

  view_->scale(1/view_->devicePixelRatio(), 1/view_->devicePixelRatio());
  view_->setInteractive(true);
  view_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
  view_->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
  view_->setRenderHint(QPainter::RenderHint::Antialiasing);
  view_->setOptimizationFlag(
      QGraphicsView::OptimizationFlag::DontSavePainterState);
  view_->setViewportUpdateMode(
      QGraphicsView::ViewportUpdateMode::FullViewportUpdate);
  entity = new MobTest();
  scene_->addItem(entity);
  scene_->setFocusItem(entity);
  showFullScreen();

  QRectF sceneRect = scene_->sceneRect();
  qreal x = sceneRect.x();
  qreal y = sceneRect.y();
  qreal width = sceneRect.width();
  qreal height = sceneRect.height();

  // if it will be just sceneRect, the user will be able to scroll the view
  // with arrow keys(it's default behaviour, I don't know how to disable it)
  view_->setSceneRect(QRectF(x + 1, y + 1, width - 2, height - 2));

  scene_->addLine(
    x + width / 2,
    y,
    x + width / 2,
    y + height,
    QPen(Qt::blue));

  scene_->addLine(
      x,
      y + height / 2,
      x + width,
      y + height / 2,
      QPen(Qt::blue));

  view_->centerOn(0, 0);

  // QTimer* timer = new QTimer(this);
  // timer->setInterval(1000);
  // timer->start();
  // connect(timer, &QTimer::timeout, this, [&](){entity->setPos(
  // entity->pos() + QPointF{100, 100});});
}
