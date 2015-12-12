TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    my_io.cpp \
    myrender.cpp \
    Main.cpp \
    globals.cpp \
    mydata.cpp \
    myscreenshot.cpp \
    vsofont.c

HEADERS += \
    globals.h \
    my_io.h \
    myrender.h \
    mydata.h \
    myscreenshot.h \
    vsofont.h \
    defines.h

LIBS+= -lopengl32 -lglu32 -lglut32

