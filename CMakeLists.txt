cmake_minimum_required(VERSION 3.10)
project(4122FinalProject)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets)

set(CMAKE_AUTOMOC  ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR  ON)


add_executable(4122FinalProject main.cpp)
target_link_libraries(4122FinalProject Bullet Enemy Game Health Player Score)