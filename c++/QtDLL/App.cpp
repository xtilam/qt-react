#include "App.h"
#include <QQmlApplicationEngine>
#include <QDir>
#include <QTimer>
#include <QResource>

#include "core/extensions/QtElementExtensions.h"
#include "core/elements/widgets/QtWindow.h"
#include "EnumDefine.h"
#include "COExports.h"
#include <iostream>

App::App(QObject *parent) : QObject(parent)
{
    if(isDev){
        int qtargc = 2;
        static char * qtargv[2];
        auto qjsDebugString = QString::fromStdString("-qmljsdebugger=port:").append(debuggerPort).toStdString();
        qtargv[0] = "App.exe";
        qtargv[1] = (char *)qjsDebugString.c_str();

        this->app = new QApplication(qtargc, qtargv);
        app->processEvents();
        this->isDev = true;
    }else{
        this->app = new QApplication(__argc, __argv);
        app->processEvents();
        this->isDev = false;
    }
    this->au3 = new Au3;
    this->ui = new UIObject;
    this->addExtension(new QtElementExtensions);
}


void App::addStyle(QString style)
{
    this->listStyle.append(style);
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
        this->app->quit();
    }
}

void App::exec()
{
    static auto qtEnums = new EnumDefine;

    if(COExports::au3Loop){
        static auto timer = new QTimer;
        timer->setSingleShot(false);
        timer->setInterval(1);
        connect(timer, &QTimer::timeout, timer, COExports::au3Loop);
        timer->start();
    }

    while(true){
        if(!this->jsEngine){
            if(isDev){
                // check reload script
                App::checkReload();
                std::thread reloadThread([](App * app){
                    while(true){
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                        app->checkReload();
                    }
                }, this);
                reloadThread.detach();
            }
            this->jsEngine = new QJSEngine;
            this->mainWindow = new QtWindow;
            for(auto ext = this->extensions.begin(); ext != this->extensions.end(); ext++){
                (*ext)->setupInit();
            }
        }else{
            this->mainWindow->reset();
            delete this->jsEngine;
            this->jsEngine = new QJSEngine;
            if(COExports::onReload) COExports::onReload();
        }
        {   // set style
            QString * styleContent = new QString();
            for(auto styleFile = listStyle.begin(); styleFile != listStyle.end(); styleFile++){
                QFile file(getRCPath(*styleFile));
                if(file.exists()){
                    file.open(QIODevice::ReadOnly);
                    styleContent->append(file.readAll() + "\n");
                    file.close();
                }else{
                    qDebug() << "not found css file: " << getRCPath(*styleFile);
                }
            }
            styleContent->replace("url(", "url(" + getRCPath("") + "/");
            this->app->setStyleSheet(*styleContent);
            delete styleContent;
        }

        engine()->installExtensions(QJSEngine::AllExtensions);
        jsEngine->evaluate(QString("this.window = this;this.__isDev__=").append(isDev ? "true" : "false"));
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

        this->app->exec();
    }
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
