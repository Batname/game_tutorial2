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
    build_tower_icon.cpp

HEADERS  += \
    game.h \
    bullet.h \
    tower.h \
    enemy.h \
    build_tower_icon.h

FORMS    +=

RESOURCES += \
    res.qrc
