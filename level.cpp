#include "level.h"

#include <algorithm>
#include <map>
#include <utility>

#include <QFile>
#include <QJsonObject>
#include <QJsonArray>

#include "GameObjects/Entities/Towers/TowerSlots/tower_slot.h"
#include "Utilities/utility.h"
#include "Utilities/Resources/pixmap_loader.h"
#include "constants.h"

Level::Level(int level_number) : level_number_(level_number) {
  QFile file(":Levels/Level" +
  QString::fromStdString(std::to_string(level_number)) + "/level.json");

  if (!file.open(QIODevice::ReadOnly)) {
    throw std::invalid_argument("There is no such level");
  }

  QByteArray level_data = file.readAll();
  QJsonParseError error;
  QJsonDocument document = QJsonDocument::fromJson(level_data, &error);
  if (error.error != QJsonParseError::NoError) {
    throw std::invalid_argument(
        "Level json parse error: " + error.errorString().toStdString());
  }

  QJsonObject root = document.object();
  startMoney_ = root.value("startMoney").toInt();

  QJsonArray tower_slot_positions = root.value("towerSlotPositions").toArray();
  tower_slots_.reserve(tower_slot_positions.size());
  for (auto tower_slot_position : tower_slot_positions) {
    int tower_slot_x;
    int tower_slot_y;
    QJsonObject tower_slot_pos_object = tower_slot_position.toObject();
    tower_slot_x = tower_slot_pos_object.value("x").toInt();
    tower_slot_y = tower_slot_pos_object.value("y").toInt();

    tower_slots_.push_back(
        new TowerSlot(VectorF(tower_slot_x, tower_slot_y)));
  }

  QJsonArray routes = root.value("routes").toArray();
  routes_.reserve(routes.size());
  for (auto route : routes) {
    QJsonArray points = route.toObject().value("points").toArray();
    std::vector<VectorF> points_for_route;
    points_for_route.reserve(points.size());
    for (auto point : points) {
      QJsonObject point_object = point.toObject();
      int x = point_object.value("x").toInt();
      int y = point_object.value("y").toInt();
      points_for_route.emplace_back(x, y);
    }
    routes_.push_back(new Route(points_for_route));
  }

  QJsonArray waves = root.value("waves").toArray();
  waves_.reserve(waves_.size());

  Time previous_wave_end_time(0);
  for (auto json_wave : waves) {
    QJsonObject wave_object = json_wave.toObject();
    Time current_wave_start_time = previous_wave_end_time +
        Time(wave_object.value("startTimeRelativeToPrevWave").toInt());
    previous_wave_end_time = current_wave_start_time;
    QJsonArray spawn_entries = wave_object.value("spawnEntries").toArray();
    Time wave_duration(0);
    std::map<Mob*, Time> mobs;
    for (auto json_spawn_entry : spawn_entries) {
      QJsonObject object = json_spawn_entry.toObject();
      SpawnEntry spawn_entry(&object);
      wave_duration = Time(std::max(
          spawn_entry.GetEntryEndTime().ms(),
          wave_duration.ms()));
      spawn_entry.AddMobsToWave(&mobs, routes_);
    }
    previous_wave_end_time += wave_duration;
    Wave* wave = new Wave(current_wave_start_time, std::move(mobs));
    waves_.push_back(wave);
  }
  QJsonArray timers_for_grow_array = root.value("GrowTimes").toArray();
  timers_for_grow_.reserve(timers_for_grow_array.size());
  for (auto i : timers_for_grow_array) {
    timers_for_grow_.emplace_back(i.toInt());
  }
}

void Level::AddObjectsToScene(GameScene* scene) {
  QPixmap* map_pixmap =
      PixmapLoader::Pixmaps::kLevelMaps.at(level_number_ - 1);
  auto map_pixmap_item = scene->addPixmap(*map_pixmap);
  map_pixmap_item->setZValue(Scene::kMapTextureZValue);

  qreal pixmap_width = map_pixmap->width();
  qreal pixmap_height = map_pixmap->height();

  QTransform transform;
  QRectF pixmap_rect(
      -pixmap_width / 2.0, -pixmap_height / 2.0,
      pixmap_width, pixmap_height);
  transform.scale(
      Scene::kWidth / pixmap_width,
      Scene::kHeight / pixmap_height);
  pixmap_rect = transform.mapRect(pixmap_rect);
  map_pixmap_item->setPos(pixmap_rect.topLeft());
  map_pixmap_item->setTransform(transform);

  for (auto tower_slot : tower_slots_) {
    scene->addItem(tower_slot);
  }
}

void Level::Tick(Time delta) {
  for (auto wave : waves_) {
    wave->Tick(delta);
  }
  if (!timers_for_grow_.empty()) {
    timers_for_grow_[0] -= delta;
  }
}

const std::vector<Route*>& Level::GetRoutes() const {
  return routes_;
}

const std::vector<Wave*>& Level::GetWaves() {
  return waves_;
}

int Level::GetLevelNumber() const {
  return level_number_;
}

int Level::GetStartMoney() const {
  return startMoney_;
}

bool Level::IsTimeForGrow() {
  if (!timers_for_grow_.empty() && timers_for_grow_[0].ms() <= 0) {
    timers_for_grow_.erase(timers_for_grow_.begin());
    return true;
  }
  return false;
}

Level::SpawnEntry::SpawnEntry(QJsonObject* spawn_root_object)
  : start_time_(Time(spawn_root_object->value("startTime").toInt())),
    mob_type_(spawn_root_object->value("mobType").toString()),
    count_(spawn_root_object->value("count").toInt()),
    entry_duration_(Time(spawn_root_object->value("entryDuration").toInt())),
    route_index_(spawn_root_object->value("routeIndex").toInt())
  {}

void Level::SpawnEntry::AddMobsToWave(
    std::map<Mob*, Time>* mobs,
    const std::vector<Route*>& routes) const {
  if (count_ == 1) {
    Mob* mob = CreateMobFromType(mob_type_);
    mob->SetRoute(routes.at(route_index_));
    mobs->insert(std::make_pair(mob, start_time_));
  }
  for (int i = 0; i < count_; ++i) {
    Time spawn_time = start_time_;
    spawn_time += entry_duration_ * ((1.0 * i) / (count_ - 1));

    Mob* mob = CreateMobFromType(mob_type_);
    mob->SetRoute(routes.at(route_index_));
    mobs->insert(std::make_pair(mob, spawn_time));
  }
}

Time Level::SpawnEntry::GetEntryEndTime() const {
  return start_time_ + entry_duration_;
}
