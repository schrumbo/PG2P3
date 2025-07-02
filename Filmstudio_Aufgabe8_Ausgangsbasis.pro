CONFIG += c++17
QT     += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drache.cpp \
    drachenart.cpp \
    drachenflug.cpp \
    drachenflugdialog.cpp \
    drachenreise.cpp \
    filmstudio.cpp \
    main.cpp \
    mainwindow.cpp \
    nachtlager.cpp \
    nachtlagerdialog.cpp \
    reiseplan.cpp \
    suchergebnisdialog.cpp

HEADERS += \
    drache.h \
    drachenart.h \
    drachenflug.h \
    drachenflugdialog.h \
    drachenreise.h \
    filmstudio.h \
    mainwindow.h \
    json.hpp \
    nachtlager.h \
    nachtlagerdialog.h \
    reiseplan.h \
    suchergebnisdialog.h

FORMS += \
    drachenflugdialog.ui \
    mainwindow.ui \
    nachtlagerdialog.ui \
    suchergebnisdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Filmstudio_Aufgabe8_Ausgangsbasis.pro.user \
    Makefile \
    Makefile.Debug \
    Makefile.Release \
    filmstudio.json \
    icons/_arrival.svg \
    icons/_delete.svg \
    icons/_departure.svg \
    icons/_help.svg \
    icons/baumkrone.svg \
    icons/beenden.svg \
    icons/bergplateau.svg \
    icons/drache.svg \
    icons/drachenflug.svg \
    icons/drachenreise.svg \
    icons/draggonport.svg \
    icons/einlesen.svg \
    icons/flug.svg \
    icons/hoehle.svg \
    icons/hoehle_.svg \
    icons/icons/_arrival.svg \
    icons/icons/_delete.svg \
    icons/icons/_departure.svg \
    icons/icons/_help.svg \
    icons/icons/baumkrone.svg \
    icons/icons/beenden.svg \
    icons/icons/bergplateau.svg \
    icons/icons/drache.svg \
    icons/icons/drachenflug.svg \
    icons/icons/drachenreise.svg \
    icons/icons/draggonport.svg \
    icons/icons/einlesen.svg \
    icons/icons/flug.svg \
    icons/icons/hoehle.svg \
    icons/icons/hoehle_.svg \
    icons/icons/landkarte.svg \
    icons/icons/nachtlager.svg \
    icons/icons/passagier.svg \
    icons/icons/poi.svg \
    icons/icons/reiseplan.svg \
    icons/icons/speichern.svg \
    icons/icons/suchen.svg \
    icons/landkarte.svg \
    icons/nachtlager.svg \
    icons/passagier.svg \
    icons/poi.svg \
    icons/reiseplan.svg \
    icons/speichern.svg \
    icons/suchen.svg

RESOURCES += \
    icons.qrc

