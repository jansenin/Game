#pragma once

#include <set>

#include <QGraphicsScene>
#include <QList>

class GraphicsItem;
class GameView;
class Mob;
class Tower;
class TowerSlot;
class Projectile;

class GameScene : public QGraphicsScene {
 public:
  GameScene(const QRectF& scene_rect, QObject* parent = nullptr);

  GameView* view();

  void removeItem(GraphicsItem* item);
  void clear();
  void addItem(GraphicsItem* item);

 private:
  std::set<Mob*> mobs_;
  std::set<Tower*> towers_;
  std::set<TowerSlot*> tower_slots_;
  std::set<Projectile*> projectiles_;
};
