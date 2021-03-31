QT += core
QT -= gui

CONFIG += c++11

TARGET = SeaBatle
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Player_human.cpp \
    Drawer.cpp \
    Player_CPU.cpp \
    Game_observe.cpp \
    Menu.cpp

HEADERS += \
    AllField.h \
    Player_human.h \
    Drawer.h \
    Player_Cpu.h \
    Game_observe.h \
    Menu.h
