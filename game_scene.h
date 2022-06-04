#pragma once

#include <vector>

#include <QGraphicsScene>
#include <QList>

class GraphicsObject;
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

  void IncCoinsCount();
  void DecCoinsCount();
  int GetCoinsCount();

  void IncCannonTowersCount();
  void DecCannonTowersCount();
  int GetCannonTowersCount();

  void IncMagicTowersCount();
  void DecMagicTowersCount();
  int GetMagicTowersCount();




  [[nodiscard]] std::vector<Mob*> Mobs() const;
  [[nodiscard]] std::vector<Tower*> Towers() const;
  [[nodiscard]] std::vector<TowerSlot*> TowerSlots() const;
  [[nodiscard]] std::vector<Projectile*> Projectiles() const;

 private:
  int coins_count_ = 0;
  int cannon_tower_count_ = 0;
  int magic_tower_count_ = 0;
};
