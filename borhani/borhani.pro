QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Logindialog.cpp \
    addcustomerdialog.cpp \
    adminwindow.cpp \
    cardtocarddialog.cpp \
    editprofile2dialog.cpp \
    editprofiledialog.cpp \
    main.cpp \
    mainwindow.cpp \
    removecustomerdialog.cpp \
    user.cpp \
    userwindow.cpp \
    viewaccountsdialog.cpp \
    viewcustomersdialog.cpp \
    viewmyaccountdialog.cpp

HEADERS += \
    Admin.h \
    LinkedList.h \
    Logindialog.h \
    User.h \
    addcustomerdialog.h \
    adminwindow.h \
    cardtocarddialog.h \
    editprofile2dialog.h \
    editprofiledialog.h \
    mainwindow.h \
    removecustomerdialog.h \
    userwindow.h \
    viewaccountsdialog.h \
    viewcustomersdialog.h \
    viewmyaccountdialog.h

FORMS += \
    Logindialog.ui \
    addcustomerdialog.ui \
    adminwindow.ui \
    cardtocarddialog.ui \
    editprofile2dialog.ui \
    editprofiledialog.ui \
    mainwindow.ui \
    removecustomerdialog.ui \
    userwindow.ui \
    viewaccountsdialog.ui \
    viewcustomersdialog.ui \
    viewmyaccountdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
