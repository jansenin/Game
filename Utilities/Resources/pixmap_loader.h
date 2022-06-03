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
    static QPixmap* kMagicProjectileLevel1;
    static QPixmap* kMagicProjectileLevel2;
    static QPixmap* kMagicProjectileLevel3;
    static QPixmap* kCannonProjectileLevel1;
    static QPixmap* kCannonProjectileLevel2;
    static QPixmap* kCannonProjectileLevel3;
    static QPixmap* kTowerSlot;
    static QPixmap* kMagicTowerLevel1;
    static QPixmap* kMagicTowerLevel2;
    static QPixmap* kMagicTowerLevel3;
    static QPixmap* kCannonTowerLevel1;
    static QPixmap* kCannonTowerLevel2;
    static QPixmap* kCannonTowerLevel3;
    static std::vector<QPixmap*> kLevelMaps;
    static QPixmap* kEmpty;

    static QPixmap* kBearTrap;
    static QPixmap* kBearTrapAnimations;
    static std::vector<QPixmap*> kBearTrapIdle;
    static std::vector<QPixmap*> kBearTrapAttacking;
    static std::vector<QPixmap*> kBearTrapBroken;
    static std::vector<QPixmap*> kBearTrapRepairing;

    static std::vector<QPixmap*> kCoinIdle;
    static QPixmap* kCoinAnimations;

    static QPixmap* kBomb0;
    static QPixmap* kBomb1;
    static QPixmap* kBomb2;
    static QPixmap* kBomb3;
    static QPixmap* kBomb4;
    static QPixmap* kBomb5;
    static std::vector<QPixmap*> kBombExplosion;
    static std::vector<QPixmap*> kBombIdle;
    static QPixmap* kBombIdleFrame;

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
    class Explosion {
     public:
      static QPixmap* kAnimations;
      static std::vector<QPixmap*> kExplosion;
    };
    class MagicProjectile {
     public:
      static QPixmap* kAnimationsLevel1;
      static QPixmap* kAnimationsLevel2;
      static QPixmap* kAnimationsLevel3;
      static std::vector<QPixmap*> kDestroyingLevel1;
      static std::vector<QPixmap*> kDestroyingLevel2;
      static std::vector<QPixmap*> kDestroyingLevel3;
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
  static void LoadExplosionAnimation();
  static void LoadBearTrapAnimations();
  static void LoadBombAnimations();
  static void LoadCoinAnimations();
  static void LoadMagicProjectileAnimations();

  static void LoadUI();
  static void LoadDefaultTextureBox();
  static void LoadMenuTextureBox();
  static void LoadMenu2TextureBox();
  static void LoadButtonTextureBox();
};
