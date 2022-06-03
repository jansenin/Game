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
        GameObjects/Entities/Mobs/test_mob.cpp
        GameObjects/Entities/Towers/tower.cpp
        GameObjects/Entities/Towers/TowerSlots/tower_slot.cpp
        GameObjects/Entities/Towers/TowerSlots/test_tower_slot.cpp
        GameObjects/Entities/Towers/test_tower.cpp
        GameObjects/Entities/Projectiles/autoguided_projectile.cpp
        GameObjects/Entities/Projectiles/test_projectile.cpp
        GameObjects/Interface/graphics_object.cpp
        GameObjects/Entities/Projectiles/projectile.cpp
        GameObjects/Entities/Mobs/skeleton.cpp
        GameObjects/Entities/Mobs/cobra.cpp
        GameObjects/Entities/Mobs/hedgehog.cpp
        GameObjects/Entities/Mobs/dwarf.cpp GameObjects/explosion.cpp GameObjects/explosion.h)

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
        Utilities/utility.cpp)

set(UI
        UI/tooltip.cpp
        UI/textured_box.cpp
        UI/linear_menu.cpp
        UI/linear_layout.cpp
        UI/button.cpp
        UI/padding_box.cpp UI/pixmap_object.cpp UI/pixmap_object.h)

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