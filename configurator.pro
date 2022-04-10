QT += quick quickcontrols2

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += \
    nsd.qrc \
    qml.qrc \
    pics.qrc \
    tree.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    builder/builder.h \
    builder/dabuilder.h \
    builder/dobuilder.h \
    builder/ldbuilder.h \
    builder/lnbuilder.h \
    cellmodel/cellmodel.h \
    eventmodel/eventmodel.h \
    proxymodel/proxymodel.h \
    nsdreader/abstractlnclass.h \
    nsdreader/cdc.h \
    nsdreader/constructedattribute.h \
    nsdreader/dataattribute.h \
    nsdreader/dataobject.h \
    nsdreader/enumeration.h \
    nsdreader/literal.h \
    nsdreader/lnclass.h \
    nsdreader/nsddata.h \
    nsdreader/nsdreader.h \
    treemodel/treeitem.h \
    treemodel/treemodel.h

SOURCES += \
    builder/builder.cpp \
    builder/dabuilder.cpp \
    builder/dobuilder.cpp \
    builder/ldbuilder.cpp \
    builder/lnbuilder.cpp \
    cellmodel/cellmodel.cpp \
    eventmodel/eventmodel.cpp \
    proxymodel/proxymodel.cpp \
    main.cpp \
    nsdreader/abstractlnclass.cpp \
    nsdreader/cdc.cpp \
    nsdreader/constructedattribute.cpp \
    nsdreader/dataattributes.cpp \
    nsdreader/dataobject.cpp \
    nsdreader/enumeration.cpp \
    nsdreader/literal.cpp \
    nsdreader/lnclass.cpp \
    nsdreader/nsddata.cpp \
    nsdreader/nsdreader.cpp \
    treemodel/treemodel.cpp

INCLUDEPATH = \
    builder \
    eventmodel \
    proxymodel \
    nsdreader \
    treemodel \
    cellmodel






