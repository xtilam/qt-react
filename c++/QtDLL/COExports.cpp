#include "COExports.h"

#include <windows.h>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextCodec>

#include "core/com_object/AllComObject.h"
#include "App.h"
#include <iostream>

using namespace std;

void setDebuggerPort(char *port)
{
    App::debuggerPort = QString::fromStdString(port);
}

COExports::COExports() : BaseObject()
{
    app = new App;
}

void COExports::setRCPath(FunctionInput *params)
{
    app->setRCPath(params->nextToQString());
}

void COExports::newObject(FunctionInput *params)
{
    params->setResultObject(new CObject);
}

void COExports::newArray(FunctionInput *params)
{
    params->setResultObject(new CArray);
}

void COExports::getDebugger(FunctionInput *params)
{
    static auto debugger = new CDebugger;
    params->setResultObject(debugger);
}

void COExports::getUI(FunctionInput *params)
{
    params->setResultObject(app->ui);
}

void COExports::exec(FunctionInput *)
{
    app->exec();
}

void COExports::addJS(FunctionInput *params)
{
    app->addJS(params->nextToQString());
}

void COExports::addStyle(FunctionInput *params)
{
    app->addStyle(params->nextToQString());
}

void COExports::addExtension(FunctionInput *params)
{
    qDebug() << "extension ptr" << params->nextToPointer();
}
BaseObject::SPrototype *COExports::getPrototype()
{
    static auto prototype = BaseObject::makePrototype<void(COExports::*)(FunctionInput *)>({
		{"setRCPath", &COExports::setRCPath},
        {"obj", &COExports::newObject},
        {"arr", &COExports::newArray},
		{"getDebugger", &COExports::getDebugger},
		{"getUI", &COExports::getUI},
		{"exec", &COExports::exec},
		{"addJS", &COExports::addJS},
		{"addStyle", &COExports::addStyle},
		{"addExtension", &COExports::addExtension},
	});
	return prototype;
}

LPDISPATCH getQtObject(void **au3Methods, void **comObjectMethods, bool isDev, LPCWSTR debugPort)
{
    if(isDev){
        CDebugger::isEnableDebug = true;
        AllocConsole();

        COORD coordInfo;
        coordInfo.X = 130;
        coordInfo.Y = 9000;

        SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coordInfo);
        SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_QUICK_EDIT_MODE | ENABLE_EXTENDED_FLAGS);
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForLocale(codec);

        App::debuggerPort = QString::fromStdWString(debugPort);
        App::isDev = true;
    }

    COExports::handleCallAction = (COExports::handleCallActionCallback) au3Methods[0];
    if(au3Methods[1] != nullptr) COExports::au3Loop = (COExports::loopAu3Callback) au3Methods[1];
    if(au3Methods[2] != nullptr) COExports::onReload = (COExports::onReloadCallback) au3Methods[2];

    BaseObject::initComObjectMethod = (BaseObject::TInitComObjectType)comObjectMethods[0];
    BaseObject::getBaseObject = (BaseObject::TGetCObject)comObjectMethods[1];
    BaseObject::allocString = (BaseObject::TAllocString)comObjectMethods[2];
    BaseObject::deleteObject = (BaseObject::TDeleteMethod)comObjectMethods[3];
    BaseObject::addRefObject = (BaseObject::TAddRef)comObjectMethods[4];
    BaseObject::releaseRefObject = (BaseObject::TRelaseRef)comObjectMethods[5];
    BaseObject::freeString = (BaseObject::TFreeString)comObjectMethods[6];
    BaseObject::setComObjectFunctions(comObjectMethods[7]);

    objExport = new COExports;
    return objExport->comobject;
}
