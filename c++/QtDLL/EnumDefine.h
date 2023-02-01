#ifndef ENUMDEFINE_H
#define ENUMDEFINE_H

#include <QObject>
#include <QJSEngine>
#include <QJsonValue>

class EnumDefine
{
public:
    class EnumData{
    public:
        QMap<QString, QVariant> map;
        QString name;
        EnumData * add(int enumValue, QString name);
        EnumData * setName(QString name);
        const QString lastData();
    };

    class DC : public QObject{
        Q_OBJECT;
    }

    const QString & enumQtMouseButton();
    const QString & enumQtKey();
    void setup(QJSEngine * engine);
};

#endif // ENUMDEFINE_H
