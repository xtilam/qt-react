#ifndef APP_H
#define APP_H

#include <QObject>
#include <QJSEngine>
#include <QApplication>
#include "Au3.h"
#include "core/com_object/UIObject.h"
#include "core/extensions/BaseExtension.h"
#include <thread>

class BaseEnum;
class QtWindow;

class App : public QObject
{
    Q_OBJECT;
    QJSEngine * jsEngine = nullptr;
    QApplication * app;
    QList<QString> listStyle;
    QList<QString> listJSRun;
    QList<BaseExtension *> extensions;
    QString rcPath = ":/";

public:
    inline static QString debuggerPort = "1234";
    inline static bool isDev = false;
    QtWindow * mainWindow;
    Au3 * au3;
    UIObject * ui;
    explicit App(QObject *parent = nullptr);
    void addStyle(QString style);
    void setRCPath(QString rcPath);
    void addJS(QString fileName);
    QJSEngine * engine();
    void checkReload();
    void exec();
    void addExtension(BaseExtension * extension);
    void addEnum(QString variable, BaseEnum * enumClass);
    const QString getRCPath(QString path);
public slots:
    void deleteObject(QObject * obj);
    QObject * timer();
signals:

};
#endif // APP_H
