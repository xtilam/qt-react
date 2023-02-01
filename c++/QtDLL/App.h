#ifndef APP_H
#define APP_H

#include <QObject>
#include <QJSEngine>
#include <QApplication>
#include "Au3.h"
#include "com_object/UIObject.h"
#include "extensions/BaseExtension.h"
#include <thread>

class App;
class BaseEnum;
class QtWindow;
typedef void (App::*loopAction)();

class App : public QObject
{
    Q_OBJECT;
    loopAction _loop;
    QJSEngine * jsEngine;
    QApplication * app;
    QString style;
    QList<QString> listJSRun;
    QList<BaseExtension *> extensions;
    QString rcPath = ":/";
    bool isDev = false;
public:
    inline static QString debuggerPort = "1234";
    QtWindow * mainWindow;
    Au3 * au3;
    UIObject * ui;
    explicit App(QObject *parent = nullptr);
    void useStyle(QString style);
    void setRCPath(QString rcPath);
    void addJS(QString fileName);
    QJSEngine * engine();
    void checkReload();
    void action_reloadLoop();
    void action_nomalLoop();
    void loop();
    void addExtension(BaseExtension * extension);
    void addEnum(QString variable, BaseEnum * enumClass);
    const QString getRCPath(QString path);
public slots:
    void deleteObject(QObject * obj);
    QObject * timer();
signals:

};
#endif // APP_H
