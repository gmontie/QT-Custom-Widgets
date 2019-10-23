
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets designer
}

lessThan(QT_MAJOR_VERSION, 5) {
    CONFIG += designer
}

CONFIG += plugin release

TEMPLATE = lib
TARGET = $$qtLibraryTarget($$TARGET)
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target

QMAKE_TARGET = QCDial

INCLUDEPATH += .
OBJECTS_DIR = ./Obj/
MOC_DIR = ./MOC/
#DESTDIR = ./Out/

HEADERS += QCDial.h   QCDialPlugin.h
SOURCES += QCDial.cpp QCDialPlugin.cpp

extra.target = extra
extra.commands = InstallLib -r ${QMAKE_TARGET}
QMAKE_EXTRA_TARGETS += extra
