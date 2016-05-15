#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T21:42:57
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TaikoDrumMaster
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    bluedrum.cpp \
    player.cpp \
    reddrum.cpp \
    score.cpp \
    time.cpp \
    button.cpp \
    runner.cpp

HEADERS  += \
    game.h \
    bluedrum.h \
    player.h \
    reddrum.h \
    score.h \
    time.h \
    button.h \
    runner.h

RESOURCES += \
    images.qrc \
    sounds.qrc
