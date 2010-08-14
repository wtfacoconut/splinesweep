TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = 3Dscanner_mk2
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += SplineDisplay.cpp GUI.cpp main.cpp ModelGenerator.cpp /home/matt/Programming/splinesweep/3Dscanner_mk2/ImageManager.cpp TextureDisplay.cpp ModelManager.cpp SplineGenerator.cpp ImageDisplay.cpp
HEADERS += GUI.h SplineGenerator.h ImageDisplay.h ModelGenerator.h common.h SplineDisplay.h TextureDisplay.h ModelManager.h /home/matt/Programming/splinesweep/3Dscanner_mk2/ImageManager.h
FORMS +=
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
