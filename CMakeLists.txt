cmake_minimum_required(VERSION 3.11.2)

project(pRPG)

find_package(SDL3 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(/usr/include)

set(SRC ${CMAKE_SOURCE_DIR}/src)

add_executable(
    rpg
    ${SRC}/main.cpp
    ${SRC}/EventDispatcher.cpp
    ${SRC}/Game.cpp
    ${SRC}/Colour.cpp
    ${SRC}/GameRectangle.cpp
    ${SRC}/rpg.cpp
)

target_link_libraries(rpg SDL3::SDL3)
