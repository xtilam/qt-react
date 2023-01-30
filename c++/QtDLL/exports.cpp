#include "exports.h"
#include <windows.h>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include "com_object/AllComObject.h"
#include <QTextCodec>
#include "App.h"

using namespace std;

//bool isDevLoad = false;
//bool isRestart = true;
//int reloadCounted = 0;
//const int maxReload = 20;
//int argc = 0;
//QDir pathReload;
//thread watchReloadSignalThread;
//QString reloadFilePath;


void enableDebug(){
    CDebugger::isEnableDebug = true;
    AllocConsole();

    COORD coordInfo;
    coordInfo.X = 130;
    coordInfo.Y = 9000;

    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coordInfo);
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_QUICK_EDIT_MODE | ENABLE_EXTENDED_FLAGS);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
}

void setComMethods(void **methods)
{
    BaseObject::initComObjectMethod = (BaseObject::TInitComObjectType)methods[0];
    BaseObject::getBaseObject = (BaseObject::TGetCObject)methods[1];
    BaseObject::allocString = (BaseObject::TAllocString)methods[2];
    BaseObject::deleteObject = (BaseObject::TDeleteMethod)methods[3];
    BaseObject::addRefObject = (BaseObject::TAddRef)methods[4];
    BaseObject::releaseRefObject = (BaseObject::TRelaseRef)methods[5];
    BaseObject::freeString = (BaseObject::TFreeString)methods[6];
}

void configMethods(void **methods)
{
    Au3Callback::handleSignal = (Au3Callback::CallbackType::handleSignal) methods[0];
    Au3Callback::onReload = (Au3Callback::CallbackType::onReload) methods[1];
}

LPDISPATCH newObject()
{
    auto obj = BaseObject::init<CObject>();
    return obj->comobject;
}

LPDISPATCH newArray()
{
    return BaseObject::init<CArray>()->comobject;
}

LPDISPATCH getDebugger()
{
    auto debugger = BaseObject::init<CDebugger>();
    return debugger->comobject;
}

void execLoopEvent()
{
    app->loop();
}

LPDISPATCH getUI()
{
    if(!app->ui){
        app->ui = BaseObject::init<UIObject>();
    }
    return app->ui->comobject;
}

void initApplication()
{
    app = new App;
}

void useStyle(LPCWSTR style)
{
    app->useStyle(QString::fromStdWString(style));
}

void addJS(LPCWSTR jsFile)
{
    app->addJS(QString::fromStdWString(jsFile));
}

void addExtension(BaseExtension *extension)
{
    app->addExtension(extension);
}

void setRCPath(LPCWSTR rcPath)
{
    app->setRCPath(QString::fromStdWString(rcPath));
}

void setDebuggerPort(char *port)
{
    App::debuggerPort = QString::fromStdString(port);
}
