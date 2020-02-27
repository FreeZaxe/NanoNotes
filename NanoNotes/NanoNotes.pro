QT += widgets

SOURCES += \
    main.cpp \
    menu.cpp \
    nouvellenote.cpp

HEADERS += \
    menu.h \
    nouvellenote.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
