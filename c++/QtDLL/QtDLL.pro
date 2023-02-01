QT += qml widgets

TEMPLATE = lib
DEFINES += QML_DLL_LIBRARY
CONFIG += c++17

SOURCES += \
    App.cpp \
    Au3.cpp \
    EnumDefine.cpp \
    Utils.cpp \
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
    elements/widgets/custom/CountConnection.cpp \
    elements/widgets/events/BaseQObjectConvert.cpp \
    elements/widgets/events/QOFocusEvent.cpp \
    elements/widgets/events/QOKeyEvent.cpp \
    elements/widgets/events/QOMouseEvent.cpp \
    elements/widgets/events/QOPoint.cpp \
    elements/widgets/events/QOPointF.cpp \
    elements/widgets/events/QOResizeEvent.cpp \
    elements/widgets/QtButton.cpp \
    elements/widgets/QtWidget.cpp \
    elements/widgets/QtWindow.cpp \
    elements/layouts/RowLayout.cpp \
    elements/widgets/custom/QWidgetCustom.cpp \
    elements/widgets/custom/QWindowCustom.cpp \
    elements/widgets/custom/QtPushButton.cpp \
    elements/widgets/events/QOSize.cpp \
    exports.cpp \
    extensions/BaseExtension.cpp \
    extensions/QtElementExtensions.cpp

HEADERS += \
    App.h \
    Au3.h \
    EnumDefine.h \
    Qt_DLL_global.h \
    Utils.h \
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
    elements/widgets/custom/CountConnection.h \
    elements/widgets/events/BaseQObjectConvert.h \
    elements/widgets/events/QOFocusEvent.h \
    elements/widgets/events/QOKeyEvent.h \
    elements/widgets/events/QOMouseEvent.h \
    elements/widgets/events/QOPoint.h \
    elements/widgets/events/QOPointF.h \
    elements/widgets/events/QOResizeEvent.h \
    elements/widgets/QtButton.h \
    elements/widgets/QtWidget.h \
    elements/widgets/QtWindow.h \
    elements/layouts/RowLayout.h \
    elements/widgets/custom/QWidgetCustom.h \
    elements/widgets/custom/QWindowCustom.h \
    elements/widgets/custom/QtPushButton.h \
    elements/widgets/events/QOSize.h \
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

