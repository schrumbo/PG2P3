CONFIG += c++17
QT     += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drache.cpp \
    drachenflug.cpp \
    drachenreise.cpp \
    filmstudio.cpp \
    main.cpp \
    mainwindow.cpp \
    nachtlager.cpp \
    reiseplan.cpp \
    suchergebnisdialog.cpp

HEADERS += \
    drache.h \
    drachenart.h \
    drachenflug.h \
    drachenreise.h \
    filmstudio.h \
    mainwindow.h \
    json.hpp \
    nachtlager.h \
    reiseplan.h \
    suchergebnisdialog.h

FORMS += \
    mainwindow.ui \
    suchergebnisdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icons/icons/_arrival.svg \
    icons/icons/_delete.svg \
    icons/icons/_departure.svg \
    icons/icons/_help.svg \
    icons/icons/beenden.svg \
    icons/icons/drache.svg \
    icons/icons/drachenreise.svg \
    icons/icons/einlesen.svg \
    icons/icons/passagier.svg \
    icons/icons/reiseplan.svg \
    icons/icons/speichern.svg \
    icons/icons/suchen.svg

