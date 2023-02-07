#ifndef COEXPORTS_H
#define COEXPORTS_H

#include "Qt_DLL_global.h"

#include <QDebug>
#include <windows.h>
#include <QtGui/QGuiApplication>
#include <QQmlApplicationEngine>
#include "App.h"

class COExports : public BaseObject{
public:
    typedef void (*handleCallActionCallback)(LPCSTR signal, LPDISPATCH params);
    typedef void (*onReloadCallback)();
    typedef void (*loopAu3Callback)() ;

    inline static handleCallActionCallback handleCallAction = nullptr;
    inline static onReloadCallback onReload = nullptr;
    inline static loopAu3Callback au3Loop = nullptr;

    explicit COExports();

    App * app;
	void setRCPath(FunctionInput * params);
    void newObject(FunctionInput * params);
    void newArray(FunctionInput * params);
	void getDebugger(FunctionInput * params);
	void getUI(FunctionInput * params);
	void exec(FunctionInput * params);
	void addJS(FunctionInput * params);
	void addStyle(FunctionInput * params);
	void addExtension(FunctionInput * params);
    void test(FunctionInput * params);
    SPrototype *getPrototype() override;
};

inline COExports * objExport = nullptr;
extern "C" QML_DLL_EXPORT LPDISPATCH __stdcall getQtObject(void ** au3Methods, void ** comObjectMethods, bool isDev, LPCWSTR debugPort);

#endif // COEXPORTS_H
