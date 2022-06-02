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
    static QPixmap* kEmpty;

    class FireTotem {
     public:
      static QPixmap* kAnimations;
      static std::vector<QPixmap*> kIdle;
      static std::vector<QPixmap*> kDisappear;
      static std::vector<QPixmap*> kAppearing;
    };

    class Skeleton {
     public:
      static std::vector<QPixmap*> kWalk;
      static std::vector<QPixmap*> kDeath;
    };

    class Cobra {
     public:
      static QPixmap* kAnimations;
      static std::vector<QPixmap*> kWalk;
      static std::vector<QPixmap*> kDeath;
    };

    class Hedgehog {
     public:
      static QPixmap* kAnimations;
      static std::vector<QPixmap*> kWalk;
      static std::vector<QPixmap*> kDeath;
    };

    class Dwarf {
     public:
      static QPixmap* kAnimations;
      static std::vector<QPixmap*> kWalk;
      static std::vector<QPixmap*> kDeath;
    };
  };

  static TexturedBoxPixmaps kMenuTexturedBoxPixmaps;
  static TexturedBoxPixmaps kMenu2TexturedBoxPixmaps;
  static TexturedBoxPixmaps kButtonTexturedBoxPixmaps;
  static TexturedBoxPixmaps kDefaultTexturedBoxPixmaps;

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
  static void LoadSkeletonAnimations();
  static void LoadCobraAnimations();
  static void LoadHedgehogAnimations();
  static void LoadDwarfAnimations();

  static void LoadUI();
  static void LoadDefaultTextureBox();
  static void LoadMenuTextureBox();
  static void LoadMenu2TextureBox();
  static void LoadButtonTextureBox();
};
