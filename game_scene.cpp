#include "game_scene.h"

#include "GameObjects/BasicObjects/Interface/graphics_item.h"
#include "game_view.h"
#include "GameObjects/BasicObjects/Entities/Mobs/Basis/mob.h"
#include "GameObjects/BasicObjects/Entities/Towers/tower.h"
#include "GameObjects/BasicObjects/Entities/Towers/TowerSlots/tower_slot.h"
#include "GameObjects/BasicObjects/Entities/Projectiles/projectile.h"

GameScene::GameScene(const QRectF& scene_rect, QObject* parent)
    : QGraphicsScene(scene_rect, parent),
    mobs_(std::set<Mob*>()),
    towers_(std::set<Tower*>()),
    tower_slots_(std::set<TowerSlot*>()),
    projectiles_(std::set<Projectile*>()) {}

GameView* GameScene::view() {
  auto result = dynamic_cast<GameView*>(QGraphicsScene::views().at(0));
  assert(result != nullptr);
  return result;
}

void GameScene::removeItem(GraphicsItem* item) {
  auto mob = dynamic_cast<Mob*>(item);
  if (mob != nullptr) {
    mobs_.erase(mob);
  }

  auto tower = dynamic_cast<Tower*>(item);
  if (tower != nullptr) {
    towers_.erase(tower);
  }

  auto tower_slot = dynamic_cast<TowerSlot*>(item);
  if (tower_slot != nullptr) {
    tower_slots_.erase(tower_slot);
  }

  auto projectile = dynamic_cast<Projectile*>(item);
  if (projectile != nullptr) {
    projectiles_.erase(projectile);
  }

  QGraphicsScene::removeItem(item);
}

void GameScene::clear() {
  mobs_.clear();
  towers_.clear();
  tower_slots_.clear();
  projectiles_.clear();

  QGraphicsScene::clear();
}

void GameScene::addItem(GraphicsItem* item) {
  auto mob = dynamic_cast<Mob*>(item);
  if (mob != nullptr) {
    mobs_.erase(mob);
  }

  auto tower = dynamic_cast<Tower*>(item);
  if (tower != nullptr) {
    towers_.erase(tower);
  }

  auto tower_slot = dynamic_cast<TowerSlot*>(item);
  if (tower_slot != nullptr) {
    tower_slots_.erase(tower_slot);
  }

  auto projectile = dynamic_cast<Projectile*>(item);
  if (projectile != nullptr) {
    projectiles_.erase(projectile);
  }

  QGraphicsScene::addItem(item);
}
