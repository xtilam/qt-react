#ifndef QTENUMS_H
#define QTENUMS_H
#include <QObject>

class QtEnums : public QObject{
    Q_GADGET
public:
    enum WindowFlags{
        Widget = Qt::WindowType::Widget,
        Window = Qt::WindowType::Window,
        Dialog = Qt::WindowType::Dialog,
        Sheet = Qt::WindowType::Sheet,
        Drawer = Qt::WindowType::Drawer,
        Popup = Qt::WindowType::Popup,
        Tool = Qt::WindowType::Tool,
        ToolTip = Qt::WindowType::ToolTip,
        SplashScreen = Qt::WindowType::SplashScreen,
        Desktop = Qt::WindowType::Desktop,
        SubWindow = Qt::WindowType::SubWindow,
        ForeignWindow = Qt::WindowType::ForeignWindow,
        CoverWindow = Qt::WindowType::CoverWindow,
        WindowType_Mask = Qt::WindowType::WindowType_Mask,
        MSWindowsFixedSizeDialogHint = Qt::WindowType::MSWindowsFixedSizeDialogHint,
        MSWindowsOwnDC = Qt::WindowType::MSWindowsOwnDC,
        BypassWindowManagerHint = Qt::WindowType::BypassWindowManagerHint,
        X11BypassWindowManagerHint = Qt::WindowType::X11BypassWindowManagerHint,
        FramelessWindowHint = Qt::WindowType::FramelessWindowHint,
        WindowTitleHint = Qt::WindowType::WindowTitleHint,
        WindowSystemMenuHint = Qt::WindowType::WindowSystemMenuHint,
        WindowMinimizeButtonHint = Qt::WindowType::WindowMinimizeButtonHint,
        WindowMaximizeButtonHint = Qt::WindowType::WindowMaximizeButtonHint,
        WindowMinMaxButtonsHint = Qt::WindowType::WindowMinMaxButtonsHint,
        WindowContextHelpButtonHint = Qt::WindowType::WindowContextHelpButtonHint,
        WindowShadeButtonHint = Qt::WindowType::WindowShadeButtonHint,
        WindowStaysOnTopHint = Qt::WindowType::WindowStaysOnTopHint,
        WindowTransparentForInput = Qt::WindowType::WindowTransparentForInput,
        WindowOverridesSystemGestures = Qt::WindowType::WindowOverridesSystemGestures,
        WindowDoesNotAcceptFocus = Qt::WindowType::WindowDoesNotAcceptFocus,
        MaximizeUsingFullscreenGeometryHint = Qt::WindowType::MaximizeUsingFullscreenGeometryHint,
        CustomizeWindowHint = Qt::WindowType::CustomizeWindowHint,
        WindowStaysOnBottomHint = Qt::WindowType::WindowStaysOnBottomHint,
        WindowCloseButtonHint = Qt::WindowType::WindowCloseButtonHint,
        MacWindowToolBarButtonHint = Qt::WindowType::MacWindowToolBarButtonHint,
        BypassGraphicsProxyWidget = Qt::WindowType::BypassGraphicsProxyWidget,
        NoDropShadowWindowHint = Qt::WindowType::NoDropShadowWindowHint,
        WindowFullscreenButtonHint = Qt::WindowType::WindowFullscreenButtonHint,
    };
    Q_ENUM(WindowFlags)
};
#endif // QTENUMS_H
