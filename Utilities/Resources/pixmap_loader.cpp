#include "pixmap_loader.h"

QPixmap* PixmapLoader::Pixmaps::kBackground;
QPixmap* PixmapLoader::Pixmaps::kTestBullet;
QPixmap* PixmapLoader::Pixmaps::kTestMob;
QPixmap* PixmapLoader::Pixmaps::kTestTower;
QPixmap* PixmapLoader::Pixmaps::kTestTowerGun;
QPixmap* PixmapLoader::Pixmaps::kTestTowerSlot;

void PixmapLoader::LoadPixmaps() {
  using P = PixmapLoader::Pixmaps;

  P::kBackground = new QPixmap(":images/background.png");
  P::kTestBullet = new QPixmap(":images/test_bullet.png");
  P::kTestMob = new QPixmap(":images/test_mob.png");
  P::kTestTower = new QPixmap(":images/test_tower.png");
  P::kTestTowerGun = new QPixmap(":images/test_tower_gun.png");
  P::kTestTowerSlot = new QPixmap(":images/test_tower_slot.png");
}
