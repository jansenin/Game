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

add_executable(Game
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
        Controller/controller.h)

target_link_libraries(Game Qt::Core Qt::Gui Qt::Widgets)