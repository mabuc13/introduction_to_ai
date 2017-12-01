TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    sokabanloader.cpp \
    ../Graph/Graph.cpp \
    ../trees/search_trees/tree.cpp \
    ../trees/search_trees/intmap.cpp

HEADERS += \
    sokabanloader.h \
    ../Graph/Graph.hpp \
    ../trees/search_trees/tree.h \
    ../trees/search_trees/intmap.h


