cmake_minimum_required(VERSION 3.1)

project(6122 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set ( SOURCES
 main.cpp
 Bullet.cpp
 Enemy.cpp
 Game.cpp
 Player.cpp
 Score.cpp
 Health.cpp
)

set ( HEADERS Bullet.h
    Enemy.h
    Game.h
    Player.h
    Score.h
    Health.h)

set ( RESOURCES
 res.qrc
)

find_package(Qt5 COMPONENTS Core Quick Gui Widgets Multimedia REQUIRED)


add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Gui Qt5::Widgets Qt5::Multimedia)

# generate proper GUI program on specified platform
if(WIN32) # Check if we are on Windows
        if(MSVC) # Check if we are using the Visual Studio compiler
                set_target_properties(${PROJECT_NAME} PROPERTIES
                        WIN32_EXECUTABLE YES
                        LINK_FLAGS "/ENTRY:mainCRTStartup"
                )
        elseif(CMAKE_COMPILER_IS_GNUCXX)
                        # SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
        else()
                message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
        endif(MSVC)
elseif(APPLE)
        set_target_properties(${PROJECT_NAME} PROPERTIES
                        MACOSX_BUNDLE YES
        )
elseif(UNIX)
        # Nothing special required
else()
        message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)
