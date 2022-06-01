#pragma once

#include <vector>

#include <QGraphicsScene>
#include <QList>

class GraphicsItem;
class GameView;
class Mob;
class Tower;
class TowerSlot;
class Projectile;
class Entity;

class GameScene : public QGraphicsScene {
 public:
  explicit GameScene(const QRectF& scene_rect, QObject* parent = nullptr);

  GameView* view();

  [[nodiscard]] std::vector<Mob*> Mobs() const;
  [[nodiscard]] std::vector<Tower*> Towers() const;
  [[nodiscard]] std::vector<TowerSlot*> TowerSlots() const;
  [[nodiscard]] std::vector<Projectile*> Projectiles() const;
};
