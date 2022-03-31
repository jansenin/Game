#include "game_field.h"
GameField::GameField() {}

GameField::GameField(
    const std::vector<Mob*>& mobs, const std::vector<TowerSlot*>& tower_slots) :
  mobs_(std::unordered_set(mobs.begin(), mobs.end())),
  tower_slots_(std::unordered_set(tower_slots.begin(), tower_slots.end())) {}

void GameField::AddMob(Mob* mob) {
  mobs_.insert(mob);
}
void GameField::AddTowerSlot(TowerSlot* tower_slot) {
  tower_slots_.insert(tower_slot);
}
const std::unordered_set<TowerSlot*>& GameField::GetTowerSlots() {
  return tower_slots_;
}
const std::unordered_set<Mob*>& GameField::GetMobs() {
  return mobs_;
}
