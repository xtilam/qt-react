#include "App.h"
#include <QQmlApplicationEngine>
#include <QDir>
#include "extensions/QtElementExtensions.h"
#include <QTimer>
#include "elements/widgets/QtWindow.h"
#include "EnumDefine.h"

App::App(QObject *parent) : QObject(parent)
{
    this->addJS("core.js");
    qDebug() << "init app";
#ifdef _RE_DEV
    static int qtargc = 2;
    static char * qtargv[2];
    auto qjsDebugString = QString::fromStdString("-qmljsdebugger=port:").append(debuggerPort).toStdString();
    qtargv[0] = "App.exe";
    qtargv[1] = (char *)qjsDebugString.c_str();

    this->app = new QApplication(qtargc, qtargv);
    this->app->processEvents();
    this->isDev = true;
    this->addJS("module.dev.bundle.js");
#else
    this->app = new QApplication(__argc, __argv);
    this->isDev = false;
    this->app->processEvents();
    this->addJS("module.bundle.js");
#endif
    this->au3 = new Au3;
    this->_loop = &App::action_reloadLoop;
    this->addExtension(new QtElementExtensions);
    qmlRegisterType<App>("react.App", 1, 0, "App");
}


void App::useStyle(QString style)
{
    this->style = style;
}

void App::setRCPath(QString rcPath)
{
    this->rcPath = QDir::cleanPath(rcPath + "/");
}

void App::addJS(QString fileName)
{
    this->listJSRun.append(fileName);
}

QJSEngine *App::engine()
{
    return this->jsEngine;
}

void App::checkReload()
{
    if(!isDev) return;
    static QDir reloadPath(getRCPath("_scriptReload.reload"));
    if(reloadPath.exists()){
        reloadPath.removeRecursively();
        this->_loop = &App::action_reloadLoop;
    }
}

void App::action_reloadLoop()
{
    static auto qtEnums = new EnumDefine;
    if(!this->jsEngine){
        this->jsEngine = new QJSEngine;
#ifdef _RE_DEV
        App::checkReload();
        std::thread reloadThread([](App * app){
            while(true){
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                app->checkReload();
            }
        }, this);
        reloadThread.detach();
#endif
        this->mainWindow = new QtWindow;
        for(auto ext = this->extensions.begin(); ext != this->extensions.end(); ext++){
            (*ext)->setupInit();
        }
    }else{
        delete this->jsEngine;
        this->jsEngine = new QJSEngine;
        this->mainWindow->window->reset();
    }
    engine()->installExtensions(QJSEngine::AllExtensions);
    if(this->style.length()){
        QFile file(getRCPath(this->style));
        if(file.exists()){
            file.open(QIODevice::ReadOnly);
            this->app->setStyleSheet(file.readAll());
            file.close();
        }else{
            qDebug() << "not found css file: " << getRCPath(this->style);
        }
    }
    jsEngine->evaluate("this.window = this; this.Qt = {};");

    ObjectContext().setName("app")->setObject(this)->setData(this->jsEngine)
            ->setName("defaultWindow")->setObject(mainWindow)->setData(this->jsEngine)
            ->setName("au3")->setObject(au3)->setData(this->jsEngine);
    qtEnums->setup(this->jsEngine);
    for(auto ext = this->extensions.begin(); ext != this->extensions.end(); ext++){
        (*ext)->setAllObject();
    }

    for(auto ext = this->extensions.begin(); ext != this->extensions.end(); ext++){
        (*ext)->setupEngine();
    }
    for(auto jsFile = listJSRun.begin(); jsFile != listJSRun.end(); jsFile++){
        auto filePath = getRCPath(*jsFile);
        QFile file(filePath);
        if(file.exists()){
            jsEngine->importModule(filePath);
        }else{
            qDebug() << "not found js file: " << filePath;
        }
    }
    this->action_nomalLoop();
    this->_loop = &App::action_nomalLoop;
}

void App::action_nomalLoop()
{
    app->processEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

void App::loop()
{
    (this->*this->_loop)();
}

void App::addExtension(BaseExtension *extension)
{
    this->extensions.append(extension);
}

const QString App::getRCPath(QString path)
{
    return QDir::cleanPath(rcPath + "/" + path);
}

void App::deleteObject(QObject *obj)
{
    delete obj;
}

QObject *App::timer()
{
    auto timer = new QTimer(this->jsEngine);
    return timer;
}
