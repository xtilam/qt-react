QT += qml widgets

TEMPLATE = lib
DEFINES += QML_DLL_LIBRARY
CONFIG += c++17
DEFINES *= QT_USE_QSTRINGBUILDER

SOURCES += \
    App.cpp \
    Au3.cpp \
    COExports.cpp \
    EnumDefine.cpp \
    Utils.cpp \
    core/com_object/BaseObject.cpp \
    core/com_object/CArray.cpp \
    core/com_object/CObject.cpp \
    core/com_object/CParams.cpp \
    core/com_object/CVariant.cpp \
    core/com_object/CDebugger.cpp \
    core/com_object/UIObject.cpp \
    core/elements/QtElement.cpp \
    core/elements/QtElementSetAttributeAction.cpp \
    core/elements/QtElementStyle.cpp \
    core/elements/layouts/BaseLayout.cpp \
    core/elements/layouts/ColumnLayout.cpp \
    core/elements/widgets/BaseWidgetElement.cpp \
    core/elements/widgets/QtLineEdit.cpp \
    core/elements/widgets/custom/CountConnection.cpp \
    core/elements/widgets/custom/QWidgetCustom.cpp \
    core/elements/widgets/custom/QWindowCustom.cpp \
    core/elements/widgets/events/BaseQObjectConvert.cpp \
    core/elements/widgets/events/QOFocusEvent.cpp \
    core/elements/widgets/events/QOKeyEvent.cpp \
    core/elements/widgets/events/QOMouseEvent.cpp \
    core/elements/widgets/events/QOPoint.cpp \
    core/elements/widgets/events/QOPointF.cpp \
    core/elements/widgets/events/QOResizeEvent.cpp \
    core/elements/widgets/QtButton.cpp \
    core/elements/widgets/QtWidget.cpp \
    core/elements/widgets/QtWindow.cpp \
    core/elements/layouts/RowLayout.cpp \
    core/elements/widgets/events/QOSize.cpp \
    core/extensions/BaseExtension.cpp \
    core/extensions/QtElementExtensions.cpp

HEADERS += \
    App.h \
    Au3.h \
    COExports.h \
    EnumDefine.h \
    Qt_DLL_global.h \
    Utils.h \
    core/enums/KeyEnum.h \
    core/enums/MouseButtonEnum.h \
    core/enums/QSizePolicyEnum.h \
    core/enums/QtEnums.h \
    core/com_object/AllComObject.h \
    core/com_object/BaseObject.h \
    core/com_object/CArray.h \
    core/com_object/CObject.h \
    core/com_object/CParams.h \
    core/com_object/CVariant.h \
    core/com_object/CDebugger.h \
    core/com_object/UIObject.h \
    core/elements/QtElementSetAttributeAction.h \
    core/elements/QtElementStyle.h \
    core/elements/QtElement.h \
    core/elements/layouts/ColumnLayout.h \
    core/elements/layouts/BaseLayout.h \
    core/elements/widgets/QtLineEdit.h \
    core/elements/widgets/BaseWidgetElement.h \
    core/elements/widgets/custom/CountConnection.h \
    core/elements/widgets/events/BaseQObjectConvert.h \
    core/elements/widgets/events/QOFocusEvent.h \
    core/elements/widgets/events/QOKeyEvent.h \
    core/elements/widgets/events/QOMouseEvent.h \
    core/elements/widgets/events/QOPoint.h \
    core/elements/widgets/events/QOPointF.h \
    core/elements/widgets/events/QOResizeEvent.h \
    core/elements/widgets/QtButton.h \
    core/elements/widgets/QtWidget.h \
    core/elements/widgets/QtWindow.h \
    core/elements/layouts/RowLayout.h \
    core/elements/widgets/custom/QWidgetCustom.h \
    core/elements/widgets/custom/QWindowCustom.h \
    core/elements/widgets/events/QOSize.h \
    core/extensions/BaseExtension.h \
    core/extensions/QtElementExtensions.h

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
#    RESOURCES += \
#        ../../ui/app.qrc
    message(dev mode)
}

