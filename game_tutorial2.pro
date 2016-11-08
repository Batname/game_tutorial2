#-------------------------------------------------
#
# Project created by QtCreator 2016-11-05T16:40:03
#
#-------------------------------------------------

QMAKE_MAC_SDK = macosx10.12
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_tutorial2
TEMPLATE = app


SOURCES += main.cpp \
    tower.cpp \
    game.cpp \
    bullet.cpp \
    enemy.cpp \
    build_brown_tower_icon.cpp \
    brown_tower.cpp \
    build_green_tower_icon.cpp \
    green_tower.cpp \
    build_red_tower_icon.cpp \
    red_tower.cpp

HEADERS  += \
    bullet.h \
    tower.h \
    enemy.h \
    build_brown_tower_icon.h \
    brown_tower.h \
    build_green_tower_icon.h \
    green_tower.h \
    build_red_tower_icon.h \
    red_tower.h \
    game.h

FORMS    +=

RESOURCES += \
    res.qrc
