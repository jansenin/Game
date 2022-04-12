#pragma once

#include <QPixmap>

class PixmapLoader {
 public:
  class Pixmaps {
   public:
    static QPixmap* kBackground;
    static QPixmap* kTestBullet;
    static QPixmap* kTestMob;
    static QPixmap* kTestTower;
    static QPixmap* kTestTowerGun;
    static QPixmap* kTestTowerSlot;
  };

  static void LoadPixmaps();
};
