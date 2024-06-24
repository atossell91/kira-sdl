cmake_minimum_required(VERSION 3.11.2)

project(pRPG)

#set(SDL3_DIR, ${CMAKE_SOURCE_DIR}/SDL/build)
#set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/SDL/build)
#find_package(SDL3 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/SDL)
include_directories(${CMAKE_SOURCE_DIR}/SDL/include)

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

#target_link_libraries(rpg SDL3::SDL3)
target_link_libraries(rpg SDL3)
