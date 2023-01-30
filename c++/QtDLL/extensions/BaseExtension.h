#ifndef BASEEXTENSION_H
#define BASEEXTENSION_H

#include <QJSEngine>
#include "../elements/QtElement.h"

class ObjectContext: public QObject{
    Q_OBJECT
public:
    QString name;
    QObject * obj;
    Q_PROPERTY(QObject * data READ r_data);
    QObject * r_data();
    explicit ObjectContext(QObject * parent = nullptr);
    ObjectContext * setObject(QObject * object);
    ObjectContext * setName(QString name);
    ObjectContext * setData(QJSEngine * engine);
};

class BaseExtension
{
private:
    QList<ObjectContext *> listObject;
public:
    BaseExtension();
    virtual void setupInit();
    virtual void setupEngine();
    void setAllObject();
    void addObject(QString name, QObject * obj);
    QJSEngine * engine();
};

#endif // BASEEXTENSION_H
