QT       += core gui widgets

TARGET = cube
TEMPLATE = app

SOURCES += main.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp \
    calendar.cpp

HEADERS += \
    mainwidget.h \
    geometryengine.h \
    calendar.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

CONFIG += c++11
LIBS   += -lopengl32
LIBS   += -lglu32
LIBS   += -lglut32

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/cube
INSTALLS += target
