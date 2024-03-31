QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autobuchung.cpp \
    booking.cpp \
    flightbooking.cpp \
    flugbuchung.cpp \
    hotelbooking.cpp \
    hotelbuchung.cpp \
    main.cpp \
    rentalcarreservation.cpp \
    trainticket.cpp \
    travelagency.cpp \
    travelagencyui.cpp \
    zugbuchung.cpp

HEADERS += \
    autobuchung.h \
    booking.h \
    flightbooking.h \
    flugbuchung.h \
    hotelbooking.h \
    hotelbuchung.h \
    rentalcarreservation.h \
    trainticket.h \
    travelagency.h \
    travelagencyui.h \
    zugbuchung.h

FORMS += \
    autobuchung.ui \
    flugbuchung.ui \
    hotelbuchung.ui \
    travelagencyui.ui \
    zugbuchung.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icon.qrc
