TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        foglalas.cpp \
        handler.cpp \
        main.cpp \
        szoba.cpp

HEADERS += \
	foglalas.h \
	handler.h \
	szoba.h

DISTFILES += \
	minta-stdout.txt


SQLAPIDIR = "D:/Downloads/SQLAPI"
INCLUDEPATH += $${SQLAPIDIR}/include
LIBS += -L$${SQLAPIDIR}/mingw-w64-x86_64-8.1.0-posix-seh-rt_v6-rev0/lib -llibsqlapi -lversion
