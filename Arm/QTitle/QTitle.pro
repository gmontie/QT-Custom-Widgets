#-------------------------------------------------
#
# Project created by QtCreator 2018-01-13T16:32:56
#
#-------------------------------------------------

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets designer
}

lessThan(QT_MAJOR_VERSION, 5) {
    CONFIG += designer
}

QT       += widgets phonon

CONFIG += designer plugin release

TARGET = QTitle
TEMPLATE = lib

DEFINES += QTITLE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#TARGET = $$qtLibraryTarget($$TARGET)
#target.path = $$[QT_INSTALL_PLUGINS]/designer
#INSTALLS += target

INCLUDEPATH += .
MOC_DIR = ./MOC/
OBJECTS_DIR = ./Obj/
#DESTDIR = ./Out/

SOURCES += QTitle.cpp \
    QTitlePlugin.cpp

HEADERS += QTitle.h \
    QTitlePlugin.h

QMAKE_TARGET = QTitle

extra.target = extra
extra.commands = InstallLib -r ${QMAKE_TARGET}
QMAKE_EXTRA_TARGETS += extra
    
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/designer
    INSTALLS += target
}
