cmake_minimum_required (VERSION 3.0.2)
project (playertwo)

set(CMAKE_CXX_STANDARD 17)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)

## edit according to specific dir/name
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.10.1/clang_64)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Core REQUIRED)
find_package (Qt5Gui REQUIRED)
find_package (Qt5Network REQUIRED)
find_package (Qt5Multimedia REQUIRED)

INCLUDE_DIRECTORIES(${QT_QTCORE_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${QT_QTGUI_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${QT_QTNETWORK_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${QT_MULTIMEDIA_INCLUDE_DIRS})

qt5_add_resources(UI_RESOURCES res.qrc)

set(SOURCE_FILES
        Bullet.cpp
        client.cpp
        Enemy.cpp
        Game.cpp
        Health.cpp
        Player.cpp
        Score.cpp
        main.cpp
        server.cpp
        )

add_library(Bullet Bullet.cpp client client.cpp Enemy Enemy.cpp Game Game.cpp Health Health.cpp Player Player.cpp Score Score.cpp)
target_link_libraries (Bullet client Enemy Game Health Player Score Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Network Qt5::Multimedia)
add_executable(playertwo ${SOURCE_FILES} ${UI_RESOURCES})
target_link_libraries (playertwo Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Network Qt5::Multimedia)
