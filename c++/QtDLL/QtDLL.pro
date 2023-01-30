QT += qml widgets

TEMPLATE = lib
DEFINES += QML_DLL_LIBRARY
CONFIG += c++17

SOURCES += \
    App.cpp \
    Au3.cpp \
    com_object/BaseObject.cpp \
    com_object/CArray.cpp \
    com_object/CObject.cpp \
    com_object/CParams.cpp \
    com_object/CVariant.cpp \
    com_object/CDebugger.cpp \
    com_object/UIObject.cpp \
    elements/layouts/BaseLayout.cpp \
    elements/widgets/BaseWidgetElement.cpp \
    elements/QtElement.cpp \
    elements/widgets/QtWidget.cpp \
    elements/widgets/QtWindow.cpp \
    elements/layouts/RowLayout.cpp \
    elements/widgets/custom/QWidgetCustom.cpp \
    elements/widgets/custom/QWindowCustom.cpp \
    exports.cpp \
    extensions/BaseExtension.cpp \
    extensions/QtElementExtensions.cpp

HEADERS += \
    App.h \
    Au3.h \
    Qt_DLL_global.h \
    com_object/AllComObject.h \
    com_object/BaseObject.h \
    com_object/CArray.h \
    com_object/CObject.h \
    com_object/CParams.h \
    com_object/CVariant.h \
    com_object/CDebugger.h \
    com_object/UIObject.h \
    elements/layouts/BaseLayout.h \
    elements/widgets/BaseWidgetElement.h \
    elements/QtElement.h \
    elements/widgets/QtWidget.h \
    elements/widgets/QtWindow.h \
    elements/layouts/RowLayout.h \
    elements/widgets/custom/QWidgetCustom.h \
    elements/widgets/custom/QWindowCustom.h \
    exports.h \
    extensions/BaseExtension.h \
    extensions/QtElementExtensions.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

ISRELEASE = $$(ISRELEASE)

equals(ISRELEASE, 1){
    DEFINES += _RE
    message(release mode)
    RESOURCES += \
        ../../ui/app.qrc
}else{
    CONFIG += qml_debug
    DEFINES += _RE_DEV
    message(dev mode)
}

