#pragma once

#include <vector>

#include <QPixmap>

#include "Utilities/animation.h"
#include "Utilities/Resources/textured_box_pixmaps.h"

class PixmapLoader {
 public:
  class Pixmaps {
   public:
    // TODO(jansenin): maybe make this readonly
    static QPixmap* kBackground;
    static QPixmap* kTestBullet;
    static QPixmap* kTestMob;
    static QPixmap* kTestTower;
    static QPixmap* kTestTowerGun;
    static QPixmap* kTestTowerSlot;
    static std::vector<QPixmap*> kLevelMaps;

    // For animations test
    class FireTotem {
     public:
      static QPixmap* kAnimations;
      static std::vector<QPixmap*> kIdle;
      static std::vector<QPixmap*> kDisappear;
      static std::vector<QPixmap*> kAppearing;
    };
  };
  static TexturedBoxPixmaps kDefaultTexturedBoxPixmaps;
  static TexturedBoxPixmaps kMenuTexturedBoxPixmaps;
  static TexturedBoxPixmaps kMenu2TexturedBoxPixmaps;
  static TexturedBoxPixmaps kButtonTexturedBoxPixmaps;

  static void LoadPixmaps();

 private:
  static std::vector<QPixmap*> CreateHorizontalFramesVector(
      QPixmap* source,
      int frame_width,
      int frame_height,
      int frames_count,
      int start_x,
      int y);

  static void LoadFireTotemAnimations();
  static void LoadUI();
  static void LoadDefaultTextureBox();
  static void LoadMenuTextureBox();
  static void LoadMenu2TextureBox();
  static void LoadButtonTextureBox();
};
