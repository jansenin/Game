cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(RESOURCES
        Resources/resources.qrc)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(GAME_OBJECTS
        GameObjects/BasicObjects/Interface/damageable.cpp
        GameObjects/BasicObjects/Interface/entity.cpp
        GameObjects/BasicObjects/Entities/Mobs/Basis/mob.cpp
        GameObjects/BasicObjects/Entities/Mobs/test_mob.cpp
        GameObjects/BasicObjects/Entities/Towers/tower.cpp
        GameObjects/BasicObjects/Entities/Towers/TowerSlots/tower_slot.cpp
        GameObjects/BasicObjects/Entities/Towers/TowerSlots/test_tower_slot.cpp
        GameObjects/BasicObjects/Entities/Towers/test_tower.cpp
        GameObjects/BasicObjects/Entities/Projectiles/autoguided_projectile.cpp
        GameObjects/BasicObjects/Entities/Projectiles/test_projectile.cpp)

set(UTILITIES
        Utilities/damage.cpp
        Utilities/time.cpp
        Utilities/vector_f.cpp
        Utilities/Resources/pixmap_loader.cpp
        Utilities/timer.cpp
        Utilities/route.cpp
        Utilities/wave.cpp
        wave_manager.cpp)

add_executable(Game
        ${RESOURCES}
        ${GAME_OBJECTS}
        ${UTILITIES}
        main.cpp
        main_window.cpp
        Controller/controller.cpp game_view.cpp game_view.h constants.cpp)

target_link_libraries(Game Qt::Core Qt::Gui Qt::Widgets)