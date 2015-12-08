#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T09:51:17
#
#-------------------------------------------------

QT       += core

QT       -= gui

QMAKE_CXXFLAGS += -Wno-c++11-extensions

TARGET    = QtC0010-Bandencentrale
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    bandencentrale.cpp \
    klant.cpp \
    factuur.cpp \
    artikel.cpp \
    velg.cpp \
    bedrijfsklant.cpp \
    band.cpp \
    globals.cpp \
    databasemanagement.cpp

HEADERS += \
    bandencentrale.h \
    klant.h \
    factuur.h \
    artikel.h \
    velg.h \
    bedrijfsklant.h \
    band.h \
    globals.h \
    databasemanagement.h
