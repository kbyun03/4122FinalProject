#-------------------------------------------------
#
# Project created by QtCreator 2018-04-18T23:27:52
#
#-------------------------------------------------

QT       += core gui \
        multimedia \
        network \


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = player2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Player.cpp \
    Score.cpp \
    Health.cpp \
    server.cpp \
    Player2.cpp

HEADERS += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Player.h \
    Score.h \
    Health.h \
    server.h \
    Player2.h

RESOURCES += \
    res.qrc
