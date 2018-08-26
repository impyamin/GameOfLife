TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    cell.cpp \
    livingcell.cpp \
    emptycell.cpp \
    board.cpp
LIBS += -L$$PWD/lib -lsfml-graphics -lsfml-window -lsfml-system
INCLUDEPATH = $$PWD/include

HEADERS += \
    cell.h \
    livingcell.h \
    emptycell.h \
    board.h
