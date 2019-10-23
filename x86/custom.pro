#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T14:12:05
#
#-------------------------------------------------

QT += core gui

TEMPLATE      = subdirs
SUBDIRS       = QLed QMeter QTitle

# install
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS custom.pro 
sources.path = $$[QT_INSTALL_EXAMPLES]/CustomQt
INSTALLS += sources

LIBS     += -lqwt 

