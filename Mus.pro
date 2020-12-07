#-------------------------------------------------
#
# Project created by QtCreator 2020-05-26T11:05:25
#
#-------------------------------------------------

QT       += core gui

TARGET = Mus
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    devicelist.cpp

HEADERS  += mainwindow.h \
    devicelist.h

FORMS    += mainwindow.ui \
    devicelist.ui

RESOURCES +=

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog


contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/Mus/bin
    INSTALLS += target
}
