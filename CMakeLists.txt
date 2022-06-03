cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(RESOURCES
        Resources/resources.qrc)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(GAME_OBJECTS
        GameObjects/Interface/damageable.cpp
        GameObjects/Interface/entity.cpp
        GameObjects/Entities/Mobs/Basis/mob.cpp
        GameObjects/Entities/Towers/tower.cpp
        GameObjects/Entities/Towers/TowerSlots/tower_slot.cpp
        GameObjects/Entities/Projectiles/autoguided_projectile.cpp
        GameObjects/Entities/Projectiles/magic_projectile.cpp
        GameObjects/Interface/graphics_object.cpp
        GameObjects/Entities/Projectiles/projectile.cpp
        GameObjects/Entities/Mobs/skeleton.cpp
        GameObjects/Entities/Mobs/cobra.cpp
        GameObjects/Entities/Mobs/hedgehog.cpp
        GameObjects/Entities/Mobs/dwarf.cpp
        GameObjects/Entities/Towers/magic_tower.cpp
        GameObjects/Entities/Towers/cannon_tower.cpp
        GameObjects/explosion.cpp
        GameObjects/Entities/Traps/bear_trap.cpp
        GameObjects/Entities/Traps/bomb.cpp
        GameObjects/coin.cpp
        GameObjects/Entities/Projectiles/linear_autoguided_projectile.cpp
        GameObjects/Entities/Projectiles/cannon_projectile.cpp)

set(UTILITIES
        Utilities/damage.cpp
        Utilities/time.cpp
        Utilities/vector_f.cpp
        Utilities/Resources/pixmap_loader.cpp
        Utilities/timer.cpp
        Utilities/route.cpp
        Utilities/wave.cpp
        wave_manager.cpp
        Utilities/animation.cpp
        Utilities/utility.cpp
        Utilities/randomaizer.cpp)

set(UI
        UI/tooltip.cpp
        UI/textured_box.cpp
        UI/linear_menu.cpp
        UI/linear_layout.cpp
        UI/button.cpp
        UI/padding_box.cpp
        UI/pixmap_object.cpp
        UI/pixmap_object.h)

add_executable(Game
        ${RESOURCES}
        ${GAME_OBJECTS}
        ${UTILITIES}
        ${UI}
        main.cpp
        main_window.cpp
        Controller/controller.cpp
        Controller/ui_controller.cpp
        game_view.cpp
        constants.cpp
        game_scene.cpp
        level.cpp)

target_link_libraries(Game Qt::Core Qt::Gui Qt::Widgets)