
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

QMAKE_TARGET = QMeter

INCLUDEPATH += .
OBJECTS_DIR = ./Obj/
#DESTDIR = ./Out/

HEADERS += QMeter.h   QMeterPlugin.h
SOURCES += QMeter.cpp QMeterPlugin.cpp

extra.target = extra
extra.commands = InstallLib -r ${QMAKE_TARGET}
QMAKE_EXTRA_TARGETS += extra

#QMAKE_POST_LINK  = InstallLib -r ${QMAKE_TARGET}
