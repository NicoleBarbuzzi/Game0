cmake_minimum_required(VERSION 3.10)
project(Game0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Character.cpp Character.h MainCharacter.cpp MainCharacter.h Monster.cpp Monster.h Weapon.h FireWeapon.cpp FireWeapon.h WhiteWeapon.cpp WhiteWeapon.h Graphic.cpp Graphic.h TileMap.cpp TileMap.h Collision.cpp Collision.h Setting.cpp Setting.h)
add_executable(Game0 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML REQUIRED network audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game0 ${SFML_LIBRARIES})
endif ()

