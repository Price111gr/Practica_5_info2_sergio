QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemigo.cpp \
    main.cpp \
    personaje.cpp \
    tablero.cpp \
    muro.cpp \
    proyectil.cpp

HEADERS += \
    enemigo.h \
    personaje.h \
    tablero.h \
    muro.h \
    proyectil.h

FORMS += \
    tablero.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc

DISTFILES += \
    mapa1.txt
    QT += multimedia
