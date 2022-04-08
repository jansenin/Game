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

add_executable(Game ${RESOURCES}
        main.cpp
        Model/BasicObjects/Interface/damagable.cpp
        Model/BasicObjects/Interface/tickable.cpp
        Model/BasicObjects/Interface/entity.cpp
        Model/BasicObjects/Entities/Mobs/Basis/mob.cpp
        Model/BasicObjects/Entities/Mobs/mob_test.cpp
        Model/BasicObjects/Entities/Towers/tower.cpp
        Model/BasicObjects/Entities/Towers/TowerSlots/tower_slot.cpp
        Model/Map/game_field.cpp
        main_window.cpp
        Utilities/damage.cpp
        Utilities/time.cpp
        View/game_view.cpp
        Controller/controller.cpp
        Utilities/resource_cacher.cpp
        Model/BasicObjects/Entities/Towers/TowerSlots/test_tower_slot.cpp
        Model/BasicObjects/Entities/Towers/test_tower.cpp
        Model/BasicObjects/Entities/Projectiles/self_directed_projectile.cpp
        Utilities/math.cpp
        Model/BasicObjects/Entities/Projectiles/test_projectile.cpp)

target_link_libraries(Game Qt::Core Qt::Gui Qt::Widgets)