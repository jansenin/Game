#include "game_scene.h"

#include "GameObjects/Interface/graphics_object.h"
#include "game_view.h"
#include "GameObjects/Entities/Mobs/Basis/mob.h"
#include "GameObjects/Entities/Towers/tower.h"
#include "GameObjects/Entities/Towers/TowerSlots/tower_slot.h"
#include "GameObjects/Entities/Projectiles/projectile.h"

GameScene::GameScene(const QRectF& scene_rect, QObject* parent)
    : QGraphicsScene(scene_rect, parent) {}

GameView* GameScene::view() {
  auto result = dynamic_cast<GameView*>(QGraphicsScene::views().at(0));
  assert(result != nullptr);
  return result;
}

std::vector<Mob*> GameScene::Mobs() const {
  std::vector<Mob*> result;
  for (auto item : items()) {
    if (auto mob = dynamic_cast<Mob*>(item)) {
      result.push_back(mob);
    }
  }
  return result;
}

std::vector<Tower*> GameScene::Towers() const {
  std::vector<Tower*> result;
  for (auto item : items()) {
    if (auto tower = dynamic_cast<Tower*>(item)) {
      result.push_back(tower);
    }
  }
  return result;
}

std::vector<TowerSlot*> GameScene::TowerSlots() const {
  std::vector<TowerSlot*> result;
  for (auto item : items()) {
    if (auto tower_slot = dynamic_cast<TowerSlot*>(item)) {
      result.push_back(tower_slot);
    }
  }
  return result;
}

std::vector<Projectile*> GameScene::Projectiles() const {
  std::vector<Projectile*> result;
  for (auto item : items()) {
    if (auto projectile = dynamic_cast<Projectile*>(item)) {
      result.push_back(projectile);
    }
  }
  return result;
}

