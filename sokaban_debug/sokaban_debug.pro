TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
SOURCES += main.cpp \
    sokabanloader.cpp \
    ../Graph/Graph.cpp

HEADERS += \
    sokabanloader.h \
    ../Graph/Graph.hpp

