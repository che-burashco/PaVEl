# -------------------------------------------------
# Project created by QtCreator 2010-04-06T09:01:26
# -------------------------------------------------
TARGET = Panguin
TEMPLATE = app

INCLUDEPATH += $(PAVELPATH)/cairo/include/cairo
INCLUDEPATH += $(PAVELPATH)/pango/include/pango-1.0
INCLUDEPATH += $(PAVELPATH)/glib/include/glib-2.0
INCLUDEPATH += $(PAVELPATH)/glib/lib/glib-2.0/include
INCLUDEPATH += $(PAVELPATH)/freetype2/include
INCLUDEPATH += $(PAVELPATH)/fontconfig/include/fontconfig
INCLUDEPATH += $(PAVELPATH)/fontconfig/include

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += main.cpp \
    mainwindow.cpp \
    TextInstance.cpp \
    TextDrawer.cpp \
    readFromFile.cpp
HEADERS += mainwindow.h \
    TextDrawer.h \
    TextInstance.h \
    TextInstance.h \
    readFromFile.h
FORMS += mainwindow.ui
LIBS += $(PAVELPATH)\cairo\lib\cairo.lib
LIBS += $(PAVELPATH)\pango\lib\pango-1.0.lib
LIBS += $(PAVELPATH)\pango\lib\pangocairo-1.0.lib
LIBS += $(PAVELPATH)\glib\lib\gobject-2.0.lib
LIBS += $(PAVELPATH)\glib\lib\glib-2.0.lib
LIBS += $(PAVELPATH)\fontconfig\lib\fontconfig.lib
