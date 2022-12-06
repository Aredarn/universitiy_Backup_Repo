TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        handler.cpp \
        lista.cpp \
        main.cpp \
        pont.cpp \
        telepules.cpp




HEADERS += \
    handler.h \
    lista.h \
    pont.h \
    telepules.h

SQLAPIDIR = "D:/Downloads/SQLAPI"
INCLUDEPATH += $${SQLAPIDIR}/include
LIBS += -L$${SQLAPIDIR}/mingw-w64-x86_64-8.1.0-posix-seh-rt_v6-rev0/lib -llibsqlapi -lversion
