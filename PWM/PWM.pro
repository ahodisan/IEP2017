QT += core
QT -= gui

CONFIG += c++11

TARGET = PWM
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bcm2835.cpp \
    pin.cpp

HEADERS += \
    bcm2835.h \
    pin.h
