#ifndef ENUMDEFINE_H
#define ENUMDEFINE_H

#include <QObject>
#include <QJSEngine>
#include <QJsonValue>

class EnumDefine
{
public:
    void setup(QJSEngine * engine);
    void registerEnum(QJSEngine * engine, const QMetaObject * obj, QString nameEnum, int enumIndex = 0);
};

#endif // ENUMDEFINE_H
