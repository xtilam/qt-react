#ifndef EXPORTS_H
#define EXPORTS_H

#include "Qt_DLL_global.h"

#include <QDebug>
#include <windows.h>
#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>
#include "App.h"

inline App * app = nullptr;

extern "C" QML_DLL_EXPORT void __stdcall enableDebug();
extern "C" QML_DLL_EXPORT void __stdcall setDebuggerPort(char * port);
extern "C" QML_DLL_EXPORT void __stdcall setRCPath(LPCWSTR rcPath);
extern "C" QML_DLL_EXPORT void __stdcall configMethods(void ** methods);
extern "C" QML_DLL_EXPORT LPDISPATCH __stdcall newObject();
extern "C" QML_DLL_EXPORT LPDISPATCH __stdcall newArray();
extern "C" QML_DLL_EXPORT LPDISPATCH __stdcall getDebugger();
extern "C" QML_DLL_EXPORT LPDISPATCH __stdcall getUI();
extern "C" QML_DLL_EXPORT void __stdcall execLoopEvent();
extern "C" QML_DLL_EXPORT void __stdcall setComMethods(void ** method);
extern "C" QML_DLL_EXPORT void __stdcall initApplication();
extern "C" QML_DLL_EXPORT void __stdcall addJS(LPCWSTR jsFile);
extern "C" QML_DLL_EXPORT void __stdcall useStyle(LPCWSTR style);
extern "C" QML_DLL_EXPORT void __stdcall addExtension(BaseExtension * extension);

namespace Au3Callback{
namespace CallbackType{
    typedef void (*handleCallActionType)(LPCSTR signal, LPDISPATCH params);
    typedef void (*onReload)();
}
    inline CallbackType::handleCallActionType handleCallAction = nullptr;
    inline CallbackType::onReload onReload = nullptr;
}

#endif // EXPORTS_H
